#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    cout << 4 * !61641564;
    return 0;
}

/*
var 01
sub 3 ex 1:
void DivX(int n, int x)
{
    while(n >= 1)
        {
            cout << n * x << " ";
            n--;
        }
}
int main()
{
    int n = 4;
    int x = 15;
    DivX(n,x);
    return 0;
}

sub 3 ex 3
#include <iostream>
#include <fstream>
using namespace std;


int main()
{
    ifstream f("bac.in");
    int n, v[100] = {0};
    while(f >> n)
    {
        if(n <= 99 && n >= 10)
            v[n]++;
    }
    int k = 0;
    for(int i = 99 ; i >= 1 && k < 2; i--)
        if(v[i] == 0 && i % 10 != i / 10)
        {
            k++;
            cout << i << " ";
        }
    if(k == 0)
         cout << "nu exista";
    f.close();
    return 0;
}


var 02:

    unsigned int n;
    int s, c1, c2 ;
    cin >> n;
    s = 1;
    c1 = n % 10;
    n = n / 10;
    c2 = n % 10;
    if(c1==c2)
        s = 0;
    else
        if(c1 < c2)
         s = -1;
    while((c1-c2)*s > 0 && n > 9)
    {
            c1 = n % 10;
    n = n / 10;
    c2 = n % 10;
    }
    cout << s << " " << n;
    return 0;

sub 2 ex 3:
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char s[101] ="PREafrUMoASA";

    if(!strchr(s,'a'))
        cout << "a";
    if(!strchr(s,'e'))
        cout << "e";
    if(!strchr(s,'i'))
        cout << "i";
    if(!strchr(s,'o'))
        cout << "o";
    if(!strchr(s,'u'))
        cout << "u";
    if(!strchr(s,'A'))
        cout << "A";
    if(!strchr(s,'E'))
        cout << "E";
    if(!strchr(s,'I'))
        cout << "I";
    if(!strchr(s,'O'))
        cout << "O";
    if(!strchr(s,'U'))
        cout << "U";

    return 0;

}

sub 3
ex 1:
#include <iostream>
using namespace std;
int factori(int n, int m)
{
    int rez = 0;
    int div = 2;
    while(n != 1 && m != 1)
    {
        int ok = 1;
        int expn = 0;
        int expm = 0;
        while(n % div == 0)
        {
            expn++;
            n = n / div;
        }
        while(m % div == 0)
        {
            expm++;
            m = m / div;
        }
        if(expn == expm && expn != 0)
        {
            for(int i = 3; i <= div / 2; i++)
                if(div % i == 0)
                    ok = 0;

            if(ok == 1)
            {
                rez++;
            }

        }
        div++;

    }
    return rez;
}
int main()
{
    int n = 16500;
    int m = 10780;
    int k = factori(n,m);
    cout << k;
    return 0;
}

ex 2:
#include <iostream>

using namespace std;

int main()
{
    int n; int a[401][401];
    cin >> n;
    for(int i =  1; i <= n; i++)
    {
        int k = i; int ok = n - 1;
        for(int j = 1; j <= n; j++)
        {
            if(k <= n)
            {
                a[i][j] = k;
                k++;
            }
            else
            {
                a[i][j] = ok;
                ok--;
            }
        }
    }
    for(int i =  1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
                cout << a[i][j] << " ";
        cout << endl;
    }

    return 0;
}

ex 3:
//nu e ok pt ca am facut numai pentru numere pare
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("bac.in");
    int n ,lungStang , lungStangFinal, lungDreapta, poz = 0;
    lungStang = 0;
    lungDreapta = 0;
    while(f >> n && poz == 0)
    {
        lungStang++;
        if(n%2==0)
            poz++;
    }
    poz = 0;
    while(f >> n)
    {
        lungDreapta++;
        if(n % 2 == 0)
        {
            lungStangFinal = lungStang;
        }
        lungStang++;
    }
    if(lungStangFinal > lungDreapta)
        cout << lungStangFinal;
    else
        cout << lungDreapta;
    return 0;
}

// ala bun cu pozitive :
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("bac.in");
    int n ,poz = 0, a , b , ok  = 0;
    while(f >> n)
    {
        poz++;
        if(n > 0 && ok == 0)
        {
            a = poz;
            ok++;
        }
        else if(n > 0)
        {
            b = poz;
        }
    }
    if(poz - a > poz - b)
        cout << poz - a + 1;
    else
        cout << poz - b + 1;

    f.close();
    return 0;
}


varianta 3
sub 2:
ex 2:
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct muzeu
{
    unsigned int numar;
    struct{
        char nume[21],colectie[21];
    }exponat[100];
}m;

int main()
{
    cin >> m.numar;
    cin >> m.exponat[2].nume;
    cin >> m.exponat[2].colectie;
    cout << m.numar << m.exponat[2].colectie << m.exponat[2].nume;
    return 0;
}


sub 3 ex 1:
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
bool numarPrim(int n)
{
    if(n < 2)
        return false;
    if(n == 2)
        return true;
    for(int i = 2; i <= n/2 ; i++)
        if(n % i == 0)
            return false;
    return true;
}
int suma(unsigned int n)
{
    int s = 1;
    for(int i = 4; i <= n; i++)
    {
        if(n % i == 0)
            if(numarPrim(i) == false)
                s = s + i;
    }
    return s;
}
int main()
{

    unsigned int n = 12;
    cout << suma(n);
    return 0;
}


sub 3 ex 2
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main()
{
    int n , m , i , j,oki = 0;
    int a[101][101];
    cin >> m >> n;
    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++)
            cin >> a[i][j];
    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++)
            if(a[i][1] == a[j][n] && a[i][1] != 0)
            {
                cout << a[i][1] << " ";
                oki = 1;
            }
    if(oki==0) cout << "nu exista";
    return 0;
}
sub 3 exercitiul 3:
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    int n, cifZeci[10] = {0}, cifPoz[10] = {0}, lung = 0;
    ifstream f("bac.in");
    while(f >> n)
    {
        lung++;
        int zeci = (n/10) % 10;
        cifZeci[zeci]++;
        cifPoz[zeci] = lung;
    }
    int maxim = cifZeci[0];
    for(int i = 1; i <= 9; i++)
        if(cifZeci[i] > maxim)
            maxim = cifZeci[i];
    for(int i = 1; i <= 9; i++)
        if(cifZeci[i] == maxim)
        {
            cout << cifPoz[i] << " ";
        }
    return 0;
}



varianta 5:
sub III:
ex 1:
int identice(unsigned int n)
{
    int u = n % 10;
    n = n / 10;
    while(n > 0)
    {
        if(n % 10 != u)
           return 0;
        u = n % 10;
        n = n / 10;
    }
    return 1;
}

int main()
{
    int n = 212;
    cout << identice(n);
    return 0;
}


ex 2 :
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    unsigned int n, m , i, j; int a[101][101];
    cin >> m >> n;
    for(i =  1; i <= m; i++)
        for(j = 1; j <= n; j++)
            a[i][j] = (i*j) % 10;
    for(i =  1; i <= m; i++)
    {
        for(j = 1; j <= n; j++)
                cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}


ex 3:
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    ifstream f("bac.txt");
    unsigned int n,i,x,maxim = 0;
    f >> n;
    for(i = 1; i <= n; i++)
    {
        f >> x;
        if(maxim < x)
            maxim = x;
        cout << maxim << " ";
    }
    return 0;
}




varianta 6:
subiectul 3:

ex 1:
#include <iostream>
using namespace std;

void numar(int  n, int c , int &m)
{
    int p = 1;
    m = 0;
    int lungime = 0;
    int egal = 0;
    if(n == 0 && c == 0)
        m = -1;
    while(n > 0)
    {
        int a = n %  10;
        n = n / 10;
        lungime++;
        if(c != a)
        {
            m = m + p * a;
            p = p * 10;
        }
        else if(c == a)
            egal++;
    }
    if(lungime == egal)
        m = -1;
}

int main()
{
    int n,c , m;
    cin >> n >> c;
    numar(n,c,m);
    cout << m;
    return 0;
}

ex 2:
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main()
{
    int i,j,n,a[21][21];
    cin >> n;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
    {
        if(i+j == n+1)
            a[i][j] = 0;
        else  if(i+j < n+1)
            a[i][j] = n + 1 -i - j;
        else
            a[i][j] = a[i-1][j] + 1;
    }

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}

ex 3:
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int n, lung , pozultneg = 0, ok, neg ,lungmax = 0;
    ifstream f("bac.in");ok = 0;lung = 0; neg = 0;
    while(f >> n)
    {
        lung++;
        if(n < 0)
            neg++;
        if(neg <= 1)
            if(lung > lungmax)
                lungmax = lung;
        if(ok == 0 && neg == 1)
        {
            pozultneg = lung;
            ok++;
        }
        if(neg == 2)
        {
            int aux = pozultneg;
            neg--;
            pozultneg = lung - aux;
            lung = aux;
        }
    }
    cout << lungmax;
    f.close();
    return 0;
}


Test 07:

subiectul III:
ex 1:
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void afisare(int x, int y, int k)
{
    int aux = k;
    for(int i = x; i <= y; i++)
    {
        int ok = 0;
        if(aux >= 1)
        {
            cout << i << " ";
            aux--;
        }
        if(aux == 0)
        {
            cout << "*";
            aux = k;
            ok = 1;
        }
        if(y == i && ok != k)
        {
            ok = 1;
        }
        if(ok == 1 && y != i)
            cout << " ";
    }
}

int main()
{
    int x =11, y =22,k = 4;
    afisare(x,y,k);
    return 0;
}

ex 2:
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    int x, i, j, n , aux;
    int a[101][101];
    n = 0; int cat = 1;
    cin >> x;
    aux = x;
    while(aux != 0)
    {
        n++;
        aux = aux / 10;
    }
    for(j = n; j >= 1; j--)
    {
        for(i = 1; i <= n; i++)
            a[i][j] = (x / cat) % 10;
        cat = cat * 10;
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}


ex 3:
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    ifstream  f("bac.txt");
    int ok = 0;
    int v[10]= {0},x;
    while(f >> x)
    {
        if(x % 2 == 0)
            v[x]++;
    }
    for(int i = 0; i <= 8; i = i + 2)
        if(v[i] != 0)
    {
        int aux = v[i];
        while(aux > 0 )
        {
            cout << i << " ";
            aux--;
            ok = 1;
        }
    }
    if(ok == 0) cout << "nu exista";
    f.close();
    return 0;
}



//testul 8:
sub III:
ex 1:
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int nrfp(int n, int &m)
{
    int okmax = 0;
    for(int i = n; i >= 2; i--)
    {
        int ok = 0;
        int d = 2;
        int aux = i;
        int exp = 0;
        while(aux > 1)
        {
            while(aux % d == 0)
            {
                exp++;
                aux = aux / d;
            }
            if(exp > 0)
                ok++;
            exp = 0;
            d++;
        }
        if(ok > okmax)
        {
            okmax = ok;
            m = i;
        }
    }
}

void nrfp(int n, int &m)
{
    int i,aux,d,e,k,maxim;
    maxim=0;
    for(i=2;i<=n;i++)//se vede ca e parcuregere interval
    {
        aux=i;//NU stric pe i ca e contor
        //descompunerea in factori primi cu numararea
        //factorilor
        k=0;//initial, pp ca aux nu are factori primi
        //k=0 pentru fiecare i in parte!!!
        d=2;
        while(aux>1)
        {
            e=0;
            while(aux%d==0)
            {
                aux=aux/d;
                e++;
            }
            if(e>0)
                k++;//numar factorii primi ai lui i (aux!!!)
            d++;
        }//gata descompunerea
        if(k>=maxim)//atentie aici la semn!!!!
            //ca sa obtin ultimul - cel mai mare
            //pun obligatoriu >= NU >
        {
            maxim=k;
            m=i;//m se tot suprascrie => ultimul cel mai mare
        }
    }
}
int main()
{
    int n, m;
    n = 100;
    nrfp(n,m);
    cout << m;
    return 0;
}

ex 2:
#include <iostream>
using namespace std;

int main()
{
    int i,j , n, a[51][51];
    int s = 0;
    cin >> n;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            cin >> a[i][j];
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            if(i < j && j != n && i+j > n + 1)
                s = s + a[i][j];
    cout << s;
    return 0;
}

ex3:
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    ifstream f("bac.txt");
    int x,imp1,imp2;
    imp1 = -1; imp2 = -1;
    while(f >> x)
    {
        if(x % 2 != 0)
        {
            imp1 = imp2;
            imp2 = x;
        }
    }
    if(imp1 == -1)
        cout << "nu exista";
    else
        cout << imp1 << " " << imp2;
    f.close();
    return 0;
}


#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int nrfp(int n, int &m)
{
    int okmax = 0;
    for(int i = n; i >= 2; i--)
    {
        int ok = 0;
        int d = 2;
        int aux = i;
        int exp = 0;
        while(aux > 1)
        {
            while(aux % d == 0)
            {
                exp++;
                aux = aux / d;
            }
            if(exp > 0)
                ok++;
            exp = 0;
            d++;
        }
        cout << ok << " " << i << endl;
        if(ok > okmax)
        {
            okmax = ok;
            m = i;
        }
    }
}

/*void nrfp(int n, int &m)
{
    int i,aux,d,e,k,maxim;
    maxim=0;
    for(i=2;i<=n;i++)//se vede ca e parcuregere interval
    {
        aux=i;//NU stric pe i ca e contor
        //descompunerea in factori primi cu numararea
        //factorilor
        k=0;//initial, pp ca aux nu are factori primi
        //k=0 pentru fiecare i in parte!!!
        d=2;
        while(aux>1)
        {
            e=0;
            while(aux%d==0)
            {
                aux=aux/d;
                e++;
            }
            if(e>0)
                k++;//numar factorii primi ai lui i (aux!!!)
            d++;
        }//gata descompunerea
        if(k>=maxim)//atentie aici la semn!!!!
            //ca sa obtin ultimul - cel mai mare
            //pun obligatoriu >= NU >
        {
            maxim=k;
            m=i;//m se tot suprascrie => ultimul cel mai mare
        }
    }
}
int main()
{
    int n, m;
    n = 100;
    nrfp(n,m);
    cout << m;
    return 0;
}





varianta 9:
sub 3:
ex 1:
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void divizor(int a, int b,int k, int &nr)
{
    nr = 0;
    for(int i = a; i <= b; i++)
        if(i%10  == k && i%k == 0)
            nr++;
}

int main()
{
    int nr,a,b;
    int k =4;
    b = 50;
    a= 3;
    divizor(a,b,k,nr);
    cout << nr;
    return 0;
}

ex 2:
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    char sir[101];
    cin.get(sir,101);
    int bun = 0;
    char *cuv = strtok(sir," ");
    while(cuv != NULL)
    {
        int ok = 0;
        int v[6] ={0};
        for(int i = 0; i < strlen(cuv);i++)
            if(cuv[i] == 'a')
                v[1]++;
            else if(cuv[i] == 'e')
                v[2]++;
            else if(cuv[i] == 'i')
                v[3]++;
            else if(cuv[i] == 'o')
                v[4]++;
            else if(cuv[i] == 'u')
                v[5]++;
        for(int  i = 1; i<= 5;i++)
            if(v[i] != 0)
                ok++;
        if(ok == 1)
        {
            cout << cuv << endl;
            bun = 1;
        }
        cuv = strtok(NULL, " ");
    }
    if(bun == 0) cout << "nu exista";
    return 0;
}

//sau tot 2:

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    char sir[101];
    char voc[] = "aeiou";
    cin.get(sir,101);
    int k,c,i;
    char *p = strtok(sir," ");
    k = 0;
    while(p != NULL)
    {
        c = 0;
        for(i = 0; i <= 4; i++)
            if(strchr(p,voc[i]) != NULL)
                c++;
        if(c == 1)
        {
            k++;
            cout << p << endl;
        }
        p = strtok(NULL, " ");
    }
    return 0;
}

ex 3:
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    int x;
    int v[10] = {0};
    ifstream f("bac.txt");
    while(f >> x)
    {
        while(x > 0)
        {
            v[x%10]++;
            x = x / 10;
        }
    }
    for(x = 9; x >= 0; x--)
        while(v[x] > 0)
        {
            cout << x;
            v[x]--;
        }
    f.close();
    return 0;
}


#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    int x;
    int v[10] = {0};
    ifstream f("bac.txt");
    while(f >> x)
    {
        while(x > 0)
        {
            v[x%10]++;
            x = x / 10;
        }
    }
    for(x = 9; x >= 0; x--)
        while(v[x] > 0)
        {
            cout << x;
            v[x]--;
        }
    f.close();
    return 0;
}




variana 11 2020:
sub 3:
ex 1:

ex 2:
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    char sir[101];
    cin.get(sir,101);
    char *cuv = strtok(sir," ");
    while(cuv != NULL)
    {
        char aux[101];
        strcpy(aux,cuv);
        if(aux[0] >= 'a' && aux[0] <= 'z')
            aux[0] = aux[0] - 32;
        for(int i = 1; i < strlen(aux);i++)
        {
            if(aux[i] >= 'A' && aux[i] <= 'Z')
                aux[i] = aux[i] + 32;
        }
        cout << aux;
        cout << " ";
        cuv = strtok(NULL," ");
    }
    return 0;
}

ex 3:
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    ifstream f("bac.txt");
    int x,ant = 0;
    f >> x;
    cout << x << " ";
    ant = x;
    int lung = 1;
    while(f >> x)
    {
        if(x != ant)
        {
            cout << lung << " ";
            lung = 1;
            cout << x << " ";
            ant = x;
        }
        else
            lung++;
    }
    cout << lung;
    f.close();
    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

void  patrate(int x, int y)
{
    int i ,s = 0;
    for(i = x; i <= y; i++)
        if((int)sqrt(i)==sqrt(i))
        {
            if(s == 0)
            {
                cout << i;
                s = s + i;
            }
            else
            {
                cout << '+'  << i;
                s = s + i;
            }
        }
        if(s != 0)
            cout << '=' << s;
        else cout << "nu exista";
}

int main()
{
    int x,y;
    cin >> x >> y;
    patrate(x,y);
    return 0;
}



// test 12 bac 2021:
III
1.
#include <iostream>
#include <cmath>
using namespace std;

void frate(int x, int &y)
{
    y = 0; int ok =0, p = 1;int uc;
    while(x > 0)
    {
        uc = x % 10;
        if(uc == 9)
            ok = 1;
        y = p *(uc+1)+y;
        p = p * 10;
        x = x / 10;
    }
    if(ok == 1) y = -1;
}

int main()
{
    int x,y;
    cin >> x;
    frate(x,y);
    cout << y;
    return 0;
}


2.
#include <iostream>
#include <fstream>
using namespace std;


int main()
{
    int n,k,i,j,aux,a[21][21];
    cin >> n >> k;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            cin >> a[i][j];
    aux =a[k][n-k];
    for(j = n;j > 1; j--)
        if(k+j < n + 1)
            a[k][j] = a[k][j-1];
    a[k][1] = aux;
    cout << endl << endl;
    for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }


    return 0;
}





#include <iostream>
#include <fstream>
using namespace std;

void DivX(int n, int x)
{
    while(n >= 1)
        {
            cout << n * x << " ";
            n--;
        }
}

int main()
{
    ifstream f("bac.in");
    int n, v[100] = {0};
    while(f >> n)
    {
        if(n <= 99 && n >= 10)
            v[n]++;
    }
    int k = 0;
    for(int i = 99 ; i >= 1 && k < 2; i--)
        if(v[i] == 0 && i % 10 != i / 10)
        {
            k++;
            cout << i << " ";
        }
    if(k == 0)
         cout << "nu exista";
    f.close();
    return 0;
}





#bac 2020 iunie

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int a,b,c,x;
    cin >> a;
    c = 0;
    do{
        b = a;
        x = 0;
        do{
            if(b % 10 == c)
                x = 1;
            b = b / 10;
        }while(b != 0 && x != 1);
        cout << x << " ";
        c = c + 2;
    }while(c <= 9);
    return 0;
}

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int n , i , j;
    int a[101][101];
    cin >> n;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            a[i][j] = '=';
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            if(i + j > n - 1 && i > j)
                a[i][j] = '<';
            else a[i][j] = '>';



    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            cout << (char)a[i][j] << " ";
        cout << endl;
    }


    return 0;
}





#include <iostream>
#include <fstream>
using namespace std;

int suma(int a, int b)
{
    int s = 0;
    for(int div = 1; div <= a && div <= b;div++)
        if(a % div == 0 && b % div == 0)
            s = div + s;
    return s;
}

int main()
{

    cout << suma(20,12);
    return 0;
}

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main()
{
    char sir[101];
    char finalu[101];
    int exist = 0;
    cin.get(sir,101);
    char *cuv = strtok(sir," ");
    while(cuv != NULL)
    {
        char aux[101];
        strcpy(aux,cuv);
        if(strlen(aux) >= 3)
        {
            exist = 1;
            int ult = aux[0];
            for(int i = 1; i < strlen(aux); i++)
                {
                    aux[i-1] = aux[i];
                }
            aux[strlen(aux) - 1] = ult;
        }
        strcat(finalu,aux);
        strcat(finalu, " ");
        cuv = strtok(NULL," ");
    }
    if(exist == 0) cout << "nu exista";
    else cout << finalu;
    return 0;
}


#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main()
{
    ifstream f("bac.in");
    int v[1001] = {0};
    int x;
    while(f >> x)
    {
        v[x]++;
    }
    int k = 0;
    for(int i = 1; i <= 1000; i++)
        if(v[i] % 2 != 0)
            k++;
    if(k > 1)
        cout << "NU";
    else
        cout << "DA";
    return 0;
}


#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main()
{
    ifstream f("bac.in");
    int v[1001] = {0};
    int x;
    while(f >> x)
    {
        v[x]++;
    }
    int k = 0;
    for(int i = 1; i <= 1000; i++)
        if(v[i] % 2 != 0)
            k++;
    if(k > 1)
        cout << "NU";
    else
        cout << "DA";
    return 0;
}


#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("bac.txt");
    int n = 0,x,p1 = 0,p2 = 0;
    while(f >> x )
    {
        n++;
        if(x > 0 && p1 == 0)
            p1 = n;
        else if(x > 0)
            p2 = n;
    }
    cout << p2;
    if(p2 != 0)
        if(n - p1 + 1 > p2)
            cout << n - p1 + 1 << "aci315" ;
        else cout << p2 << "aci3";
    if(p2 == 0)
        if(p1 > n / 2)
         cout << p1 << "acedei";
        else if(n / 2 == p1)
            cout << n - p1  + 1 << "aci";

    f.close();
    return 0;
}



var 3 ultima prob:
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f1("bac.in");
    ifstream f2("bac.txt");
    int n1,n2;
    int x1, x2;
    f1 >> n1;
    f2 >> n2;
    int ult = 0;
    f1 >> x1;
    f2 >> x2;
    int lungx1 = 0;
    int lungx2 = 0;
    int prima = 0;
    int ok = 0;
    while(lungx1 < n1 && lungx2 < n2)
    {
        if(x1 < x2)
        {
            if(x1 % 5 == 0 && ult != x1)
            {
                cout << x1 << " ";
                ult = x1;
            }
            lungx1++;
            f1 >> x1;
            if(lungx1 == n1 + 1) prima = 1;
        }
        else if(x1 > x2)
        {
            if(x2 % 5 == 0 && ult != x2)
            {
                cout << x2 << " ";
                ult = x2; ok = 1;
            }
            f2 >> x2;
            lungx2++;
        }
        else
        {
            f1 >> x1;
            f2 >> x2;
            lungx1++;
            lungx2++;
        }
    }
    if(prima == 1 || n2 == 0)
    {
        while(lungx1 < n1 )
        {
            if(x1 % 5 == 0 && ult != x1)
            {
                cout << x1 << " ";ok = 1;
                ult = x1;
            }
            lungx1++;
            f1 >> x1;
        }
    }
    else if(prima == 0 || n1 == 0)
    {
        while (lungx2 < n2)
        {

            if(x2 % 5 == 0 && ult != x2)
            {
                cout << x2 << " ";ok = 1;
                ult = x2;
            }
            f2 >> x2;
            lungx2++;
        }
    }
    if(ok == 0) cout << "nu exista";

    f1.close();
    f2.close();
    return 0;
}


var 7:
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    unsigned int n,x,y,c;
    cin >> x;
    n = 0;
    while(x != 0)
    {
        y = x; c = 0;
        while(y > 0)
        {
            if(y % 10 > c)
                c = y % 10;
            y = y / 10;
        }
        n = n * 10 + c;
        cin >> x;
    }
    cout << n;
    return 0;
}


sub 3:
#include <iostream>
#include <fstream>

using namespace std;

void afisare(int x, int y, int k)
{
    int nr = 0;
    for(int i = x; i <= y; i++)
    {
        cout << i << " ";
        nr++;
        if(nr == k)
        {
            cout << "*" << " ";
            nr = 0;
        }
    }
    if(nr != 0)
        cout << "*";
}

int main()
{
    afisare(11,23,4);
    return 0;
}


#include <iostream>
#include <fstream>

using namespace std;

int main()
{
     long long int v[20] ={0};
     long long int a[20][20];
    long long int n = 0;
    long long int x;
    cin >> x;
    while(x > 0)
    {
        int uc = x % 10;
        x = x / 10;
        n++;
        v[n] = uc;
    }
    x = n;
    for(int j = 1; j <= n; j++)
        {
            for(int i = 1; i <= n; i++)
            {
                a[i][j] = v[x];
            }
            x--;
        }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("bac.txt");
    int v[9] = {0};
    int x;
    int ok = 0;
    while(f >> x)
    {
        if(x % 2 == 0)
            v[x]++;
    }
    for(int i = 0; i <= 8; i = i + 2)
    {
        while(v[i] > 0)
        {
            v[i]--;
            cout <<i << " ";
            ok = 1;
        }
    }
    if(ok == 0) cout << "nu exista";
    f.close();
    return 0;
}


#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("bac.txt");
    int v[9] = {0};
    int x;
    int ok = 0;
    while(f >> x)
    {
        if(x % 2 == 0)
            v[x]++;
    }
    for(int i = 0; i <= 8; i = i + 2)
    {
        while(v[i] > 0)
        {
            v[i]--;
            cout <<i << " ";
            ok = 1;
        }
    }
    if(ok == 0) cout << "nu exista";
    f.close();
    return 0;
}


#include <iostream>
#include <fstream>

using namespace std;

int identice(int n)
{
    int uc = n % 10;
    n = n / 10;
    while(n)
    {
        if(uc != n % 10)
            return 0;
        n = n / 10;
    }
    return 1;
}

int main()
{
    cout << identice(212);
    return 0;
}



#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;



int main()
{
    ifstream f("bac.in");
    int x;
    int ok = 0;
    int neg2,lung = 0;
    while(f >> x)
    {
        lung++;
        if(x < 0 && ok !=2)
        {
            neg2 = lung;
            ok++;
        }
    }
    if(lung - neg2 >= neg2)
    {
        cout << lung - neg2 ;
    }
    else cout << neg2 ;


    return 0;
}


#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    ifstream f("bac.in");
    int x,neg1 = -1, neg2 = -1,neg3 = -1;
    int lung = 0;
    while(f >> x)
    {
        lung++;
        if(x < 0 && neg1 == -1)
        {
            neg1 = lung;
        }
        else if(x < 0 && neg2 == -1)
        {
            neg2 = lung;
        }
        else if(x < 0)
            neg3 = lung;
    }
    int a = neg2 - 1;
    int b = neg3 - neg1 - 1;
    int c = lung - neg2;
    if( a < b )
        a = b;
    if(a < c)
        a = c;
    cout << a;
    return 0;
}


#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int numar(int n , int c, int &m)
{
    int ok = 0;
    m = 0;
    int p = 1;
    while(n > 0)
    {
        int uc = n % 10;
        n = n / 10;
        if(uc != c)
        {
            ok = 1;
            m = m + uc * p;
            if(m != 0)
                p = p * 10;
        }
    }
    if(ok == 0)
        m = -1;
}

int main()
{
    int m;
    numar(55,5,m);
    cout << m;
    return 0;
}


#include <iostream>

using namespace std;

int main()
{
    int n; int a[401][401];
    cin >> n;
    int k =n;
    for(int i =  1; i <= n; i++)
    {
        k--;int ka =1;
        int puf = k;
        for(int j = 1; j <= n; j++)
        {
            if(i + j == n + 1)
                a[i][j] = 0;
            else if(i + j < n + 1)

            {
                a[i][j] = puf;
                puf--;
            }
            else
            {
                a[i][j] = ka;
                ka++;
            }
        }
    }
    for(int i =  1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
                cout << a[i][j] << " ";
        cout << endl;
    }

    return 0;
}


#include <iostream>

using namespace std;

int main()
{
    int n; int a[401][401];
    cin >> n;
    int x = n;
    int l = 0;
    while(x > 0)
    {
        l++;
        x = x / 10;
    }
    x = n;
    for(int  j = l; j >= 1; j --)
    {
        for(int i = l; i >= 1; i--)
            a[i][j] = x % 10;
        x = x / 10;
    }

    for(int i =  1; i <= l; i++)
    {
        for(int j = 1; j <= l; j++)
                cout << a[i][j] << " ";
        cout << endl;
    }

    return 0;
}

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    ifstream f("bac.txt");
    int par1 = -1;
    int par2 = -1;
    int x;
    int ok = 0;
    while(f >> x)
    {
        if(x % 2 != 0)
        {
            if(par1 == -1)
                par1 = x;
            else if(par2 == -1 && par1 != -1)
            {
                par2 = x;ok = 1;
            }
            else
            {

                par1 = par2;
                par2 = x;
            }
        }
    }
    if(ok == 1) cout << par1 <<" " << par2;
    else cout << "ce-am facut sefu?";
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int n; int a[401][401];
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        for(int  j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    int s = 0;
    for(int i = 1; i < n; i++)
    {
        for(int  j = 1; j < n; j++)
                if((i + j > n + 1) && (i < j))
                {
                    cout << endl << a[i][j];
                    s = s + a[i][j];
                }
    }
    cout << endl;
    cout << s;


    return 0;
}




#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int nrfp(int n, int &m)
{
    m = 0;
    int avemmax = 0;
    for(int i = n; i >= 2; i--)
    {
        int aux = i;
        int exp = 0;
        int div = 2;
        int avem = 0;
        while(aux > 1)
        {
            while(aux % div == 0)
            {
                exp++;
                aux = aux / div;
            }
            if(exp != 0)
                avem++;
            div++;
            exp = 0;
        }
        if(avem > avemmax)
        {
            avemmax = avem;
            m = i;
        }
        else if(avem == avemmax && avem !=0)
            if(m < i) m = i;
    }
}
int main()
{
    int m;
    nrfp(100,m);
    cout << m;
    return 0;
}



#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void divizor(int a,int b, int k, int &nr)
{
    nr = 0;
    for(int i = a; i <= b;i++)
    {
        if(i % k == 0 && i % 10 == k)
        {
            nr++;
        cout << i << endl;

        }
    }
}
int main()
{
    int m;
    divizor(3,50,4,m);
    cout << m;
    return 0;
}
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    ifstream f("bac.txt");
    int x;
    int v[10] = {0};
    while(f >> x)
    {
        while(x > 0)
        {
            v[x % 10]++;
            x = x / 10;
        }
    }
    for(int i = 9;i >= 0;i --)
        while(v[i] > 0)
    {
        v[i]--;
        cout << i;
    }
    f.close();
    return 0;
}

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    char s[101];
    cin.get(s,101);
    char *cuv = strtok(s," ");
    while(cuv!= NULL)
    {
        char aux[101];
        strcpy(aux,cuv);
        int ok1,ok2,ok3,ok4,ok5;
        ok1=ok2=ok3=ok4=ok5=0;
        for(int i = 0; i < strlen(aux);i++)
            if(aux[i] == 'a')
                ok1 = 1;
            else if(aux[i] == 'e')
                ok2 = 1;
            else if(aux[i] == 'i')
                ok3 = 1;
            else if(aux[i] == 'o')
                ok4 = 1;
            else if(aux[i] == 'u')
                ok5 = 1;
        int s = ok1+ok2+ok3+ok4+ok5;
        if(s == 1) cout << cuv << endl;
        cuv = strtok(NULL, " ");
    }
    return 0;
}


#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    char s[101];
    cin.get(s,101);
    int fain = 0;
    char *cuv = strtok(s," ");
    while(cuv!= NULL)
    {
        char aux[101];
        strcpy(aux,cuv);
        int ok1,ok2,ok3,ok4,ok5;
        ok1=ok2=ok3=ok4=ok5=0;
        for(int i = 0; i < strlen(aux);i++)
            if(aux[i] == 'a')
                ok1 = 1;
            else if(aux[i] == 'e')
                ok2 = 1;
            else if(aux[i] == 'i')
                ok3 = 1;
            else if(aux[i] == 'o')
                ok4 = 1;
            else if(aux[i] == 'u')
                ok5 = 1;
        int s = ok1+ok2+ok3+ok4+ok5;
        if(s == 1) {cout << cuv << endl;fain = 1;}
        cuv = strtok(NULL, " ");
    }
    if(fain == 0)
        cout <<"fainuc";
    return 0;
}
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    ifstream f("bac.txt");
    int x;int lung = 1;
    int primu;
    f >> primu;
    while(f >> x)
    {
        if(x < primu)lung++;
    }
    cout << lung;
    return 0;
}


#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    //ifstream f("bac.txt");
    int x,y;
    cin >> x >> y;
    cout << y << " " << x << " ";
    while(x > 1)
    {
        int aux = x;
        x = x -(y - x - 2);
        y = aux;
        cout << x << " ";
    }
    return 0;
}

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    ifstream f("bac.txt");
    int x, lung = 1;
    int primu;
    f >> primu;
    int mari = 0;
    while(f >> x)
    {
        lung++;
        if(x < primu)
            mari++;
    }
    cout << lung - mari;
    f.close();
    return 0;
}


#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    //try 4 15 0 1 3
    int a,s,b,x,y,z;
    cin >> a;
    s = 0;
    for(int i = 1; i <= 4; i++)
    {
        cin >> b;
        x = a;
        y = b;
        z = 0;
        while(x != 0)
        {
            if(x % 2 == 1)
                z = z + y;
            x = x / 2;
            y = y * 2;
        }
        s = s + z;
        cout << z;
        cout << endl;
        a = b;
    }
    cout << s;
    return 0;
}




#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    int N = 9;
    int a[100][100] = {0};
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (a[i][j] == 0)
            {
                a[i][j] = i;
                a[j][i] = i;
            }
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}



#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    //try 4 15 0 1 3
    int a,s,b,x,y,z;
    cin >> a;
    s = 0;
    for(int i = 1; i <= 4; i++)
    {
        cin >> b;
        x = a;
        y = b;
        z = 0;
        while(x != 0)
        {
            if(x % 2 == 1)
                z = z + y;
            x = x / 2;
            y = y * 2;
        }
        s = s + z;
        cout << z;
        cout << endl;
        a = b;
    }
    cout << s;
    return 0;
}

*/
