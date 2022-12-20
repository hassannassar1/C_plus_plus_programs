#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
class Box{
    
//l,b,h are integers representing the dimensions of the box
    private:
        int l, b, h;
        
// The class should have the following functions : 
    public:
// Constructors: 
// Box();
        Box(){
            l=b=h=0;
        }
// Box(int,int,int);
        Box(int ll, int bb, int hh){
            l = ll;
            b = bb;
            h = hh;
        }
// Box(Box);
        Box(Box& box){
            l = box.l;
            b = box.b;
            h = box.h;
        }
    
// int getLength(); // Return box's length
        int getLength(){
            return l;
        }
// int getBreadth (); // Return box's breadth
        int getBreadth (){
            return b;
        }
// int getHeight ();  //Return box's height
        int getHeight (){
            return h;
        }
// long long CalculateVolume(); // Return the volume of the box
        long long CalculateVolume(){
            return (long long)l*h*b;
        }
//Overload operator < as specified
//bool operator<(Box& b)
        bool operator<(Box& box){
            if (l<box.l){
                return true;
            }
            else if ((b<box.b) && (l==box.l)){
                return true;
            }
            else if ((h<box.h) &&(b<box.b)&&(l==box.l))
            return true;
            
            return false;
        }

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)
        
};
ostream& operator<<(ostream& out, Box& B){
            out << B.getLength() << " " << B.getBreadth() << " " <<                                                         B.getHeight();
            return out;
        }

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}