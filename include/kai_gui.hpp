#ifndef KAI_GUI_HPP
#define KAI_GUI_HPP

#include "canvas.hpp"

namespace kai
{
    class MenuGUI: public Canvas {
        public:
        MenuGUI();
        ~MenuGUI() = default;
        void drawGUI() override;
        int playBttnId;
     };

     class PlayGUI: public Canvas {
        public:
        PlayGUI();
        ~PlayGUI() = default;
        void drawGUI() override;
     };
}

#endif