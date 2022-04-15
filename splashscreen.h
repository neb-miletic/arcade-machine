using namespace std;

class Splashscreen {
    private:
        // Vector of buttons
        vector<Button*> btns;
        // Bitmap to be drawn as background
        string bmp;
        // Check if play has been clicked
        bool playClicked = false;
        // CHeck if exit has been clicked
        bool exitClicked = false;
        // A selector
        Selector select;
    public:
        // Default constructor
        Splashscreen(){}
        // Overloaded constructor
        Splashscreen(const string &bitmap)
        {
            this->bmp = bitmap;
        }

        void add_button(Button *b)
        {
            this->btns.push_back(b);
        }

        bool getPlayClick()
        {
            return playClicked;
        }

        bool getExitClick()
        {
            return exitClicked;
        }

        void draw_title_page()
        {            
            // Draw background image to screen
            draw_bitmap(this->bmp, 0, 0);

            if (this->btns.size() > 0)
            {
                // Arcade Machine title
                draw_text("Arcade",  COLOR_BLACK, "title_font", 100, 1200, 100);
                draw_text("Machine", COLOR_BLACK, "title_font", 100, 1180, 200);
                
                // Draw buttons to screen
                for (int i = 0; i < btns.size(); i++)
                {
                    this->btns[i]->draw_button();
                }

                // Draw text on buttons
                draw_text("play!", COLOR_BLACK, "btn_font", 70, btns[0]->x() - (btns[0]->centre_x()/2) + 5, btns[0]->y() - btns[0]->centre_y()+5);
                draw_text("options", COLOR_BLACK, "btn_font", 70, btns[1]->x() - (btns[1]->centre_x()/2) - 20, btns[1]->y() - btns[1]->centre_y()+5);
                draw_text("exit", COLOR_BLACK, "btn_font", 70, btns[2]->x() - (btns[2]->centre_x()/2) + 20, btns[2]->y() - btns[2]->centre_y()+5);

                select.check_key_input(this->btns);
                
                draw_text("Created By", COLOR_BLACK, 1200, 850);
                draw_text("Sarah", COLOR_BLACK, 1200, 870);
                draw_text("Anthony", COLOR_BLACK, 1200, 890);
                draw_text("Riley", COLOR_BLACK,  1200, 910);
                draw_text("Huy", COLOR_BLACK, 1200, 930);
            }
        }

        void button_clicked(point_2d point)
        {
            // If mouse is at button sprite position.
            if (sprite_at(btns[2]->btn(), point))
            {
                // If the mouse is then clicked.
                if (mouse_clicked(LEFT_BUTTON))
                {
                    // Button clicked is true.
                    exitClicked = true;
                    write_line("exit BUTTON CLICKED");
                    exit_program();
                }
            }
            if (sprite_at(btns[0]->btn(), point))
            {
                // If the mouse is then clicked.
                if (mouse_clicked(LEFT_BUTTON))
                {
                    // Button clicked is true.
                    playClicked = true;
                    write_line("Play button clicked");
                }
            }
        }

         void exit_program()
        {
            abort();
        }
};