#include <iostream>

class Palindromic
{

    private:
    // Declaring storing cells for maximum unequals input i and j. 
    int MAX=0, max_i=0, max_j=0;
    // Declaring storing cells for maximum equals input i.  
    int MAXEQ=0, meq_i=0;
    // Declaring range.   
    int N=0, n=0;

    public:
    //Getting search range from user
    void setRange() {
        std::cout << "\nEnter high border: ";
        std::cin >> N;
        std::cout << "\nEnter lower border: ";
        std::cin >> n;
    }

    // Function boolean "not_reverse_skip" swap digits
    // for decimal-input number, write it to rev,
    // then return "1" if k is not palindrome and "0"
    // if palindrome
    bool not_reverse_skip(long long k) {
        long long x=k, rev=0;
        while (x)
            {
            rev=rev*10+(x%10);
            x/=10;
            }
        if(k==rev) return false;
        else return true;
    }

    // Calculate maximum palindrome product from unequal input
    void calcUnPal() {
        // Declaring and initialize  
        long long product=0;
        
        for(int i=N;i>=n;i--) {
            for(int j=N;j>=n;j--) {
                product=i*j;
                if(not_reverse_skip(product)) continue; 
                if(MAX<product)
                        MAX=product; max_i=i; max_j=j; break;
            }
        }   
    }

    // Calculate maximum palindrome product from equal input
    void calcEqPal() {  
        // Declaring and initialize  
        long long product=0;
            
        for(int i=N;i>=n;i--) {
                product=i*i;
                if(not_reverse_skip(product)) continue; 
                if(MAXEQ<product)
                        MAXEQ=product; meq_i=i; break;
        }
    }

    //Print result of calculation when terminate class
    ~Palindromic() {
        std::cout<<"\nThe maximum palindrome product from unequal inputs\n";
        std::cout<<"between "<<N<<" and "<<n<<" input is:\n";
        std::cout<<max_i<<" * "<<max_j<<" = "<<MAX<<".\n";
        std::cout<<"\nThe maximum palindrome product from equal inputs\n";
        std::cout<<"between "<<N<<" and "<<n<<" input is:\n";
        std::cout<<meq_i<<" * "<<meq_i<<" = "<<MAXEQ<<".\n";
    }

};

// And now actual program.
int main() {

    Palindromic *arrow;
    arrow = new Palindromic;

    arrow->setRange();
 
    arrow->calcUnPal();

    arrow->calcEqPal();

    // By deleting pointer we will recieve result ot the screen
    delete arrow;
}