#pragma once

#include <unordered_map>
#include <string>
#include <raylib.h>

namespace kai
{

    class Assets
    {
    public:
        static Assets &get()
        {
            static Assets instance;
            return instance;
        }

        // ---------------------------------------------------------
        // Ciclo de vida del gestor
        // ---------------------------------------------------------

        void init()
        {
            Image img = GenImageColor(2, 2, MAGENTA);
            missingTexture = LoadTextureFromImage(img);
            UnloadImage(img);

            defaultFont = GetFontDefault();
        }

        void shutdown()
        {
            clear();

            if (missingTexture.id > 0)
            {
                UnloadTexture(missingTexture);
                missingTexture = {};
            }
        }

        void clear()
        {
            for (const auto &item : textures)
                UnloadTexture(item.second);
            for (const auto &item : sounds)
                UnloadSound(item.second);
            for (const auto &item : music)
                UnloadMusicStream(item.second);
            for (const auto &item : fonts)
                UnloadFont(item.second);

            textures.clear();
            sounds.clear();
            music.clear();
            fonts.clear();
        }

        // ---------------------------------------------------------
        // Carga segura bajo demanda
        // ---------------------------------------------------------

        Texture2D getTexture(const std::string &filename)
        {
            std::string path = texturePath + filename;

            if (textures.find(path) != textures.end())
            {
                return textures[path];
            }

            if (!FileExists(path.c_str()))
            {
                TraceLog(LOG_WARNING, "Recurso no encontrado: %s", path.c_str());
                return missingTexture;
            }

            Texture2D texture = LoadTexture(path.c_str());
            textures[path] = texture;
            return texture;
        }

        Font getFont(const std::string &filename)
        {
            std::string path = fontPath + filename;

            if (fonts.find(path) != fonts.end())
            {
                return fonts[path];
            }

            if (!FileExists(path.c_str()))
            {
                TraceLog(LOG_WARNING, "Fuente no encontrada: %s", path.c_str());
                return defaultFont;
            }

            Font font = LoadFontEx(path.c_str(), 32, nullptr, 250);
            fonts[path] = font;
            return font;
        }

        Sound getSound(const std::string &filename)
        {
            std::string path = soundPath + filename;

            if (sounds.find(path) != sounds.end())
            {
                return sounds[path];
            }

            if (!FileExists(path.c_str()))
            {
                TraceLog(LOG_WARNING, "Sonido no encontrado: %s", path.c_str());
                return Sound{};
            }

            Sound sound = LoadSound(path.c_str());
            sounds[path] = sound;
            return sound;
        }

        Music getMusic(const std::string &filename)
        {
            std::string path = musicPath + filename;

            if (music.find(path) != music.end())
            {
                return music[path];
            }

            if (!FileExists(path.c_str()))
            {
                TraceLog(LOG_WARNING, "Musica no encontrada: %s", path.c_str());
                return Music{};
            }

            Music track = LoadMusicStream(path.c_str());
            music[path] = track;
            return track;
        }

        // ---------------------------------------------------------
        // Descarga puntual de recursos
        // ---------------------------------------------------------

        void unloadTexture(const std::string &filename)
        {
            std::string path = texturePath + filename;
            auto it = textures.find(path);
            if (it != textures.end())
            {
                UnloadTexture(it->second);
                textures.erase(it);
            }
        }

        void unloadFont(const std::string &filename)
        {
            std::string path = fontPath + filename;
            auto it = fonts.find(path);
            if (it != fonts.end())
            {
                UnloadFont(it->second);
                fonts.erase(it);
            }
        }

        void unloadSound(const std::string &filename)
        {
            std::string path = soundPath + filename;
            auto it = sounds.find(path);
            if (it != sounds.end())
            {
                UnloadSound(it->second);
                sounds.erase(it);
            }
        }

        void unloadMusic(const std::string &filename)
        {
            std::string path = musicPath + filename;
            auto it = music.find(path);
            if (it != music.end())
            {
                UnloadMusicStream(it->second);
                music.erase(it);
            }
        }

    private:
        Assets() = default;
        ~Assets() = default;

        // Rutas base actualizadas
        std::string texturePath = "textures/";
        std::string soundPath = "sounds/";
        std::string musicPath = "music/";
        std::string fontPath = "fonts/";

        // Almacenamiento en caché
        std::unordered_map<std::string, Texture2D> textures;
        std::unordered_map<std::string, Sound> sounds;
        std::unordered_map<std::string, Music> music;
        std::unordered_map<std::string, Font> fonts;

        // Recursos seguros por defecto
        Texture2D missingTexture{};
        Font defaultFont{};
    };

}