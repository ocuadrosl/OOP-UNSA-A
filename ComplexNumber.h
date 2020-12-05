#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include <iostream>


class ComplexNumber
{
    int Real{0};
    int Imaginary{0};

public:
    ComplexNumber() = default ;
    ComplexNumber(int real, int imaginary):
        Real{real}, Imaginary{imaginary}
    {

    }

    friend std::ostream& operator<<(std::ostream&  output, const  ComplexNumber& complexNumber)
    {
       /* if(complexNumber.Real == 0 && complexNumber.Imaginary != 0)
        {
            output<<complexNumber.Imaginary<<"i";
        }

        else if(complexNumber.Imaginary < 0)
        {
            output<<complexNumber.Real<<" - "<<(-1*complexNumber.Imaginary)<<"i";
        }
        else if (complexNumber.Imaginary > 0){
            output<<complexNumber.Real<<" + "<<complexNumber.Imaginary<<"i";
        }
        else
        {
            output<<complexNumber.Real;
        }*/


        if(complexNumber.Real != 0)
        {
            output<<complexNumber.Real<<" ";
        }
        if(complexNumber.Imaginary > 0)
        {
            output<<"+";
        }
        if(complexNumber.Imaginary != 0)
        {
            output<<complexNumber.Imaginary<<"i";
        }
        output<<"\n";
        return output;

    }


    ComplexNumber& operator +=(const ComplexNumber& other)
    {
        this->Real += other.Real;
        this->Imaginary += other.Imaginary;

        return *this;
    }

    friend ComplexNumber operator+ (const ComplexNumber& a, const ComplexNumber& b)
    {
        return {a.Real+ b.Real , a.Imaginary+b.Imaginary};
    }

    friend ComplexNumber operator- (const ComplexNumber& a, const ComplexNumber& b)
    {
        return {a.Real- b.Real , a.Imaginary-b.Imaginary};
    }

    friend ComplexNumber operator* (const ComplexNumber& a, const ComplexNumber& b)
    {
        return {(a.Real*b.Real) - (a.Imaginary*b.Imaginary),
                (a.Real*b.Imaginary)+(b.Real*a.Imaginary)};
    }

    friend bool operator == (const ComplexNumber& a, const ComplexNumber& b)
    {
        return (a.Real != b.Real)? false: (a.Imaginary != b.Imaginary) ? false: true;
    }

};




#endif // COMPLEXNUMBER_H
