#include"airy.h"
#include<math.h>
#define h1_coefficient 0.355028
#define h2_coefficient 0.258819
#define flg 1.0e-5

double airy(double x){
    return h1(x)-h2(x);
}


double h1(double x1){
    int i=0;//counter
    double old_data1=0,new_data1=2.0;
    while(flg<fabs(old_data1-new_data1)){
        old_data1=new_data1;
        
        if(i==0){
            new_data1=1.0;
        }else{
            new_data1+=(h1_multiplication_function(i)/factrical_function(3*i))*pow(x1,3*i);
        }i+=1;
    }


    return h1_coefficient*new_data1;
}

double h2(double x2){
    int i=0;//counter
    double old_data2=0.0,new_data2=2.0;
    while(flg<fabs(old_data2-new_data2)){
        old_data2=new_data2;
        //new_data2=0;
        if(i==0){
            new_data2=x2;
        }else{
            new_data2+=(h2_multiplication_function(i)/factrical_function(3*i+1))*pow(x2,3*i+1);
        }i+=1;
    }

    return h2_coefficient*new_data2;
}

//factorial function()
double factrical_function(int a){
    if(a<=0){
        return 1;
    }else{
        return a*factrical_function(a-1);
    }
}

//multiplication function of h1(x)
double h1_multiplication_function(int a){
    if(a<=0){
        return 1;
    }
    else{
        return (3*a-2)*h1_multiplication_function(a-1);
    }
}
//multiplication function of h2(x)
double h2_multiplication_function(int a){
    if(a<=0){
        return 1;
    }else{
        return (3*a-1)*h2_multiplication_function(a-1);
    }
}