#include<Magick++.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
using namespace Magick;
typedef long long ll;


// g++ p1.cpp -o [object_name] $(Magick++-config --cppflags --cxxflags --ldflags --libs)

int main(int argc, char **argv)
{

    cout << "Enter filename :";
    string nm;
    cin >> nm;
    ll CODE[] ={ 0, 1, 0, 1, 1, 0, 1, 0 };
    cout << "Do you want to initialize your own array[Y/n]?";
    char ch;
    cin >> ch;
    if(ch=='Y' || ch=='y')
    {
        cout << "Enter CODE array 8 elements {0,1 only}" << endl;
        for(int x=0;x<8;x++)
        {
            cin >> CODE[x];
        }
    }
    ll w=1000;
    vector<ll> gen(w, 0);
    vector<ll> ngen(w);
    gen[w/2]=1;
    int z=0;
    unsigned char ar[3000000];
    int c=0;
    while (z<1000)
    {
        z++;
        for (int x=0;x<w;x++)
        {
            // cout << x << " " << z << endl;
            int num;
            num= gen[((x-1+w)%w)] + gen[((x+w)%w)]*2 + gen[((x+1+w)%w)]*4;
            ngen[x]=CODE[num];
            if (gen[x]==0)
            {
                ar[c++]=255;
                ar[c++]=255;
                ar[c++]=255;
            }
            else
            {
                ar[c++]=0;
                ar[c++]=0;
                ar[c++]=0;
            }

        }
        gen=ngen;
    }
    InitializeMagick(*argv);

    // Create Image object and read in from pixel data above
    Image image;
    image.read(1000, 1000, "RGB", CharPixel, ar);

    // Write the image to a file - change extension if you want a GIF or JPEG
    image.write(nm+".png");


}