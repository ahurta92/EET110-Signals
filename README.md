# Final Assignment

Sine waves form the foundations of many concepts in physics and signal processing.
Today we are going to use CPP to generate sine waves.

[Sine Waves](https://en.wikipedia.org/wiki/Sine_wave)

Its most basic form as a function of time (t) is:

$$y(t)=A\sin(2\pi ft+\varphi)$$
$$y(t)=A\cos(2\pi ft+\varphi)$$

where:

- $A$, is the amplitude
- $f$ , is the ordinary frequency
- $\omega=2\pi f$, is the angular frequency
- $\varphi$, is the phase

In this assignment we are going to develop a set of frequencies that will help us generate a
set of signals.

## Problem 1

As a first step we need to create a function that generates a time range for our signals.
Write a function that generates a sequence of time values from an initial time $t_0$ to a
final time $t_f$ using $N$ points.

```cpp
vector<double> time(double t0,double t1,int N){
	
	return vector<double>;
}
```

### Testing

- Use this function to generate a sequence of 100 points between $t_0=0$ and $t_1=1$

## Problem 2

Now we can move on to write functions that generate our sinusoidal signals.  Write two functions
that implement the above formulas. The functions should take in a `vector<double>` representing the time and return a `vector<double>` of the corresponding values.  You will also input $A$,$f$ and the $\varphi$.


```cpp
vector<double> sine(double Amplitude,double frequency,double phase,vector<double> time){
	
	return vector<double>;
}
```

```cpp
vector<double> cosine(double Amplitude,double frequency,double phase,vector<double> time){
	
	return vector<double>;
}
```


### Testing

Using the time function defined in problem 1 generate a vector representing the following 6 functions.

- $f_1(t)=10*\sin(2\pi t)$
- $f_2(t)=10*\cos(2\pi t)$
- $f_3(t)=10*\sin(2\pi t+\pi/2)$
- $f_4(t)=10*\sin(4\pi t+\pi/2)$
- $f_5(t)=10*\cos(4\pi t+\pi/2)$
- $f_6(t)=10*\cos(8\pi t+\pi/2)$


## Problem 3

As a part of our analysis we will write functions that perform certain useful operations on our signals.
Write and implement functions that takes in two signals and returns a signal that performs
the following operations on the two signals.

**Add two signals**
```cpp
vector<double> add_signals(const vector<double> &a,const vector<double> &b){
	
	return vector<double>;
}
```

**Subtract two signals**

```cpp
vector<double> subtract_signals(const vector<double> &a,const vector<double> &b){
	
	return vector<double>;
}
```

### Testing

In order to test the implementation create the following functions

- $f_7(t)=f_1(t)+f_2(t)$
- $f_8(t)=f_1(t)+f_2(t)$
- $f_9(t)=f_1(t)-f_3(t)$


## Problem 4 Challenge Problem

In this last problem we will write a function that creates a square wave.  Write that squares an
input signal.  Your function should measure the amplitude of the incoming signal.  Then if a value $f(t)>0$ set the value to $+A$.  If the value is $f(i)<0$ set corresponding value to $-A$. If $f(t)=0$ set the value to $0$.

```cpp
vector<double> square_wave(const vector<double> &input){
	
	return vector<double>;
}
```

### Testing

Apply the square function to any of your functions to check the implementation.

- $f_{10}(t)=\text{square}(f_1)$


## The main program

You can download all the source code at [EET110 Signals](https://github.com/ahurta92/EET110-Signals/.)

You can write all your code in the following main program.  In its present state the program 
is designed to print your data to csv file "data.csv". This should help you in testing that your program works correctly.  Use your favorite program to plot the data to make sure your program generates the correct values.

```cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

void writeSignalsToFile(vector<double> t, const vector<vector<double>> & f,const string & filename){
    ofstream ofs{filename};
    if(ofs) {
        for (auto i = 0; i < t.size(); i++) {
            ofs << t[i];
            for (auto e: f) {
                ofs << ", " << e[i];
            }
            ofs   << endl;
        }
    }else{
        cout<<"Warning: did not open file"<<endl;
    }
    ofs.close();
}



int main() {
    vector<double> t={0 ,.01,.02,.03,.04,.05};// you will need to edit all of these to use your functions
    vector<double> f(t.size());
    vector<double> f1(t.size());
    vector<double> f2(t.size());
    vector<double> f3(t.size());
    vector<double> f4(t.size());
    vector<double> f5(t.size());
    vector<double> f6(t.size());
    vector<double> f7(t.size());
    vector<double> f8(t.size());
    vector<double> f9(t.size());
    vector<double> f10(t.size());
    for(auto i = 0; i < t.size();i++){
        f[i]=cos(i);
        f1[i]=sin(i);
    }
    // This function just prints your data to a comma separated value file
   auto data= {t,f,f1,f2,f3,f4,f5,f6,f7,f8,f8,f10};// you can add functions here

    writeSignalsToFile(t,data,"testing.csv");
    // you can check the output in Excel

}
```

# HAVE FUN ! :)