#ifndef __TwoDMATRIX_HPP
#define __TwoDMATRIX_HPP

class TwoDMatrix
{
    public:
        int *memo;
        int h_len;
        int v_len;
    public:
        TwoDMatrix (int _h, int _v) 
        {
            this->h_len = _h;
            this->v_len = _v;
            memo = new int[_h * _v];
            for (int i = 0; i < _h; i++) {
                for (int j = 0; j < _v; j++) {
                    this->reset(i, j); 
                }
            }
        }

        ~TwoDMatrix ()
        {
            delete this->memo;
        }

        void set(int _x, int _y)
        {
            *(memo + (h_len*_x) + _y) = 1;
        }

        void reset(int _x, int _y)
        {
            *(memo + (h_len*_x) + _y) = 0;
        }

        int get (int _x, int _y)
        {
            return *(memo + (h_len*_x) + _y);
        }
};


#endif // __TwoDMATRIX_HPP
