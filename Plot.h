#ifndef PLOT_H
#define PLOT_H

#include <Estate.h>

class Plot : public Estate
{
   public:
        Plot();
        Plot(string, string, float, float, vector<Communication>);
        Plot(const Plot& other);
        void print() const;

        vector<Communication> GetCom() const;
        void SetCom();

    private:
        vector<Communication> com;
};

#endif // PLOT_H
