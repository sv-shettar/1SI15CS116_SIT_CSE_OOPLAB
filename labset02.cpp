#include<iostream>
using namespace std;

class Distance
{
    int iDiM, iDiCm;

    public:
        Distance(){}
//      Distance(){iDiM=0; iDiCm =0;}
        Distance(int, int);
        void fnReadData(void);

        Distance operator+(Distance);

        friend ostream& operator<<(ostream&, Distance);
};

Distance::Distance(int m, int cm)   //Distance d(30,40);
        :iDiM(m),iDiCm(cm)
{
}

void Distance :: fnReadData(void)
{
    cout << "Enter the distance\n";
    cin >> iDiM >> iDiCm;
}

Distance Distance :: operator+(Distance d2)
{
    Distance d3(0,0);

    d3.iDiM = iDiM + d2.iDiM;

    d3.iDiCm = iDiCm + d2.iDiCm;

    while(d3.iDiCm >= 100)
    {
        d3.iDiM++;
        d3.iDiCm -= 100;
    }

    return d3;
}

ostream& operator<<(ostream& out,Distance m)
{
    out<< m.iDiM << "metres and " << m.iDiCm << "centimetres\n";

    return out;
}


int main(void)
{
    Distance d1(10,30), d2(20,70),d3;

    d3 = d1 + d2;

    cout << d1 << endl << d2 << endl << d3 << endl;

    Distance d4,d5,d6;

    d4.fnReadData();
    d5.fnReadData();

    d6 = d4 + d5;

    cout << d4 << endl << d5 << endl << d6 << endl;

    return 0;
}
