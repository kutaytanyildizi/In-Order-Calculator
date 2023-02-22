#include<iostream>

using namespace std;

class calculator
{
    private:
    float numArr[2];
    string op;

    public:
    calculator();
    ~calculator(){}
    void calculatorBase();
    void setNumber();
    float getNumber() const{return numArr[1];}
    void setOp();
    string getOp() const{return op;}
    bool controlNum(string floatNum);
    bool controlOp(string stringOp);
    void addNum();
    void subNum();
    void mulNum();
    void divNum();
};

calculator::calculator()
{
    cout<<"--------------------Serial Calculator---------------------"<<endl;
    cout<<"Enter the actions  you want to be performed, respectively."<<endl;
}

void calculator::setNumber()
{
    string floatNum = "null";
    int counter = 0;

    while(!(controlNum(floatNum)))
    {
        if(counter>0)
        {
            cout<<"You entered an invalid number."<<endl;
        }
        cout<<"Please enter the number:";
        cin>>floatNum;
        counter++;
    }
    numArr[1]=std::stof(floatNum);
}

void calculator::setOp()
{
    string stringOp = "0";
    int counter = 0;
    while(!(controlOp(stringOp)))
    {
        if(counter>0)
        {
            cout<<"You entered an invalid operator."<<endl;
        }
        cout<<"Please enter the operator:";
        cin>>stringOp;
        counter++;
    }
    op = stringOp;
}

bool calculator::controlNum(string floatNum)
{
    for(int i = 0; i<floatNum.size(); i++)
    {
        if(!(('0'<=floatNum[i] && floatNum[i]<='9') ||(floatNum[i]=='.' || floatNum[i]=='-')))
        {
            return false;
        }
    }
    return true;
}

bool calculator::controlOp(string stringOp)
{
    if(stringOp=="+" || stringOp=="-" || stringOp=="*" || stringOp=="/" || stringOp=="=")
    {
        return true;
    }
    else
    {
        return false;
    }
}

void calculator::calculatorBase()
{   

    op="0";
    setNumber();
    int counter = 0;
    while(op != "=")
    {
        if(counter<=0)
        {
            numArr[0] = numArr[1];
            counter++;
        }
        setOp();
        if(op!="=")
        {
            setNumber();
        }
        if(op=="+")
        {
            addNum();
        }
        else if(op=="-")
        {
            subNum();
        }
        else if(op=="*")
        {
            mulNum();
        }
        else if(op=="/")
        {
            divNum();
        }
    }

    cout<<"="<<numArr[0]<<endl;
}

void calculator::addNum()
{
    numArr[0]=numArr[0]+numArr[1];
}

void calculator::subNum()
{
    numArr[0]=numArr[0]-numArr[1];
}

void calculator::mulNum()
{
    numArr[0]=numArr[0]*numArr[1];
}

void calculator::divNum()
{
    numArr[0]=numArr[0]/numArr[1];
}