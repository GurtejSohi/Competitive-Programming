// =================================== STRINGS =====================================================

// split a string
vector<string> split(string const &input) { 
    istringstream buffer(input);
    vector<string> ret((istream_iterator<string>(buffer)), istream_iterator<string>());
    return ret;
}


// length of string
s.length();

// convert int/double to string : c++11
std::string s = std::to_string(42);

// convert string to int : 
stoi()

// convert string to double :
stod()


// substring:
std::string str="We think in generalities, but we live in details."; // (quoting Alfred N. Whitehead)
std::string str2 = str.substr (3,5);     // "think"
std::size_t pos = str.find("live");      // position of "live" in str
std::string str3 = str.substr (pos);     // get from "live" to the end

// sort string
string word = "dcab";
std::sort(word.begin(), word.end());  // sorts in-place; word = "abcd";
sort(word.rbegin(), word.rend());     // word = "dcba";




// =================================== CONTAINERS =====================================================

// find : 
// using std::find with array and pointer:
int myints[] = { 10, 20, 30, 40 };
int * p;
p = std::find (myints, myints+4, 30);
if (p != myints+4)
  std::cout << "Element found in myints: " << *p << '\n';
else
  std::cout << "Element not found in myints\n";
// using std::find with vector and iterator:
std::vector<int> myvector (myints,myints+4);
std::vector<int>::iterator it;
it = find (myvector.begin(), myvector.end(), 30);
if (it != myvector.end())
  std::cout << "Element found in myvector: " << *it << '\n';
else
  std::cout << "Element not found in myvector\n";



// ----------------------------------- ARRAYS -------------------------------------------------
// sort an array with your comparator:
bool mycomp1(pair< pair<int, int>, int> a, pair< pair<int, int>, int> b){
  int c1 = a.first.first;
  int p1 = a.first.second;
  int c2 = b.first.first;
  int p2 = b.first.second;
  if (p1 != p2) return p1 > p2;
  else return c1 > c2; 
}
pair< pair<int, int>, int> req[N]; // req((ci, pi), ind)
sort(req, req + n, mycomp1);


// finding max/min element in array:
cout << "Index of max element: " << distance(A, max_element(A, A + N)) << endl;

int myints[] = {3,7,2,5,6,4,9};
std::cout << "The smallest element is " << *std::min_element(myints,myints+7) << '\n';


//memset
memset(dp, 0, sizeof(dp));
// for 2d array:
memset(array, 0, sizeof(array[0][0]) * m * n);
memset(array, 0, sizeof(array));  // this also works

// copy an array into another array
copy(arr, arr + n, arr2);


// ----------------------------------- VECTORS -------------------------------------------------

//assign vector :  Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
std::vector<int> first;
std::vector<int> second;
std::vector<int> third;

first.assign (7,100);             // 7 ints with a value of 100

std::vector<int>::iterator it;
it=first.begin()+1;

second.assign (it,first.end()-1); // the 5 central values of first

int myints[] = {1776,7,4};
third.assign (myints,myints+3);   // assigning from array.
// ------------------------------------------------------


// inserting into a vector ----------------------------------
#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> myvector (3,100);  // (size, initial value)
  std::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );  // insert at it val 200

  myvector.insert (it,2,300);

  // "it" no longer valid, get a new one:
  it = myvector.begin();

  std::vector<int> anothervector (2,400);
  myvector.insert (it+2,anothervector.begin(),anothervector.end());

  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}

Output:
myvector contains: 501 502 503 300 300 400 400 200 100 100 100
// ------------------------------------------------------------


// lower_bound/upper_bound example : container must be sorted to use these fns
int myints[] = {10,20,30,30,20,10,10,20};
std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

std::vector<int>::iterator low,up;
low=std::lower_bound (v.begin(), v.end(), 20); //          ^
up= std::upper_bound (v.begin(), v.end(), 20); //                   ^

std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
std::cout << "upper_bound at position " << (up - v.begin()) << '\n';

Output:
lower_bound at position 3
upper_bound at position 6
// ------------------------------------------------------


// erase in vector:
std::vector::erase
iterator erase (iterator position);
iterator erase (iterator first, iterator last);
// set some values (from 1 to 10)
for (int i=1; i<=10; i++) myvector.push_back(i);
// erase the 6th element
myvector.erase (myvector.begin()+5);
// erase the first 3 elements:
myvector.erase (myvector.begin(),myvector.begin()+3);
// ------------------------------------------------------

// initialising size of a 2D vector:
vector< vector<int> > ans(2*A-1, vector<int>(2*A-1));

// remove the last element in the vector, effectively reducing the container size by one
myvector.pop_back();  // opposite of push_back(i);


// ----------------------------------- SET -------------------------------------------------
// In set(implemented as BST), insertion and deletion take place in O(logn) time.(counterpart of map(tree map))
// In unordered_set(implemented as hash map), insertion and deletion take place in O(1) expected time(worst case culd be O(n)).(counterpart of unordered_map)

//Using custom comparator for set: https://stackoverflow.com/questions/2620862/using-custom-stdset-comparator
// ex - used in 899E

// erase in set:
set<int> s;
s.insert(4);  s.insert(8);
auto it = s.begin();
s.erase(it);    // it won't be a valid pointer here
cout << << *it << " " << *s.begin() << endl; // 4 8; it still points to 4

// So, instead of s.erase(it), do:
s.erase(it++);


// ----------------------------------- ORDERED SET -------------------------------------------------
// ordered tree: (C++ STL: Policy based data structures  Codeforces)
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
or
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
find_by_order() && order_of_key():

ordered_set X;
X.insert(1);
X.insert(2);
X.insert(4);
X.insert(8);
X.insert(16);

cout<<*X.find_by_order(1)<<endl; // 2
cout<<*X.find_by_order(2)<<endl; // 4
cout<<*X.find_by_order(4)<<endl; // 16
cout<<(end(X)==X.find_by_order(6))<<endl; // true

cout<<X.order_of_key(-5)<<endl;  // 0
cout<<X.order_of_key(1)<<endl;   // 0
cout<<X.order_of_key(3)<<endl;   // 2
cout<<X.order_of_key(4)<<endl;   // 2
cout<<X.order_of_key(400)<<endl; // 5
// ------------------------------------------------------


// ----------------------------------- MULTISET -------------------------------------------------
//find no. of coccurences
int myints[]={10,73,12,22,73,73,12};
std::multiset<int> mymultiset (myints,myints+7);
std::cout << "73 appears " << mymultiset.count(73) << " times in mymultiset.\n";
// ------------------------------------------------------


// ----------------------------------- QUEUE -------------------------------------------------
queue<int> q;
q.push(5);
int x = q.front();
q.pop();

// ----------------------------------- OTHERS -------------------------------------------------
map<int, int> m1;   // tree map : keys are ordered; O(logn) - insertion, deletion, find ...
unordered_map<int, int> m2; // hash map; avg - O(1) but worst case O(n)
set<int> s1;
unordered_set<int> s2;
// doubly linked list : list
list<int> mylist (2,100);         // two ints with a value of 100
mylist.push_front (200);
mylist.push_front (300);
// used mylist in problem 899E -> see in topic-wise practice->linked list


// =================================== I/O =====================================================
// ifstream : read input from a file ; getline : read one line from input
ifstream input;
input.open(filename);
string transactionLine;
while(getline(input, transactionLine)) {


// write to a file
void writeFile(string ans){
  ofstream outp;
  outp.open("output.txt");
  outp << ans;
  outp.close();
}


// get input untill you get EOF
while(cin >> s){


// flush the output
cout << "? " << start;
fflush(stdout);
cin >> val >> next_index;

// scan / read long long int:
long long p, q;
scanf("%lld %lld", &p, &q);

// How do I print a double value with full precision using cout?
// You can set the precision directly on std::cout and use the std::fixed format specifier.
double d = 3.14159265358979;
cout.precision(17); // 17 places including the digits before the decimal.
cout << "Pi: " << fixed << d << endl;

// faster input:
ios_base::sync_with_stdio(false);
cin.tie(NULL);



// =================================== MISC =====================================================
// generate random nos. and ofstream : write output to a file
srand (time(NULL));
ofstream outf;
outf.open("ran input");
for(int i = 0; i < 1e7; ++i){
	int x = rand()%int(1e5);
	outf << x << "\n";
}
outf.close();


// inclusion exclusion
int n; // the number of sets in the set A
int result = 0; //final result, the cardinality of sum of all subsets of A
for(int b = 0; b < (1 << n); ++b)
{
     vector<int> indices;
     for(int k = 0; k < n; ++k)
     {
          if(b & (1 << k))
          {
               indices.push_back(k);
          }
     }
     int cardinality = intersectionCardinality(indices);
     if(indices.size() % 2 == 1) result += cardinality;
     else result -= cardinality;
}
cout << result << endl;
// This method of iterating over all subsets of some set using indicator vector is a super handy method 
// and it is important to remember and master it. The idea is pretty simple, since there are 2n subsets of a set of n elements, 
// each integer in a range [0,2n) represents an indicator vector of one such subset when this integer is interpreted as a binary number.	


// macros
INT_MIN
INT_MAX

// square root
dis = sqrt(double(x*x + y*y));

// 
const int N = 2e5;
int a[2e3];		// compilation error
// bcoz 2e3 is treated as float.

// never use:
if (5 <=7 <= 9) // bcoz : if (5 <= 7 < 6) passes this test


// bitwise and:&, or:|, xor:^;
// never do:
while(x & 1 == 0){		// WRONG because of precedence
while((x & 1) == 0){	// RIGHT
// ------------------------------------------------------

// ------------------------------------------------------
random_shuffle(seeds.begin(), seeds.end());
seeds.resize(k);
// ------------------------------------------------------

// some shortcuts:
for (auto it = mapToBePrinted.begin(); it != mapToBePrinted.end(); ++it) ...
for (set<int> s1: transactions){


// int main(int argc, char *argv[]){
int main(int argc, char *argv[]){
  if(argc != 3){
    cerr << "Enter 2 inputs: ./a.out <input_filename> <X> \n";
    return 0;
  }
  numTotalTransactions = readFile(argv[1]);
  double X = stod(argv[2]);
}
// ------------------------------------------------------


// measure time taken for something -------------------------------------
#include <time.h>
#include <sys/time.h>

double get_time(){
  struct timeval tp;
  gettimeofday(&tp, NULL);
  return ((double) tp.tv_sec + (double) tp.tv_usec * 1e-6);
}
int main(){
  double t1 = get_time();
  // do something
  double t2 = get_time();
  cerr << "Elapsed time2: " << t2-t1 << endl;
}
// ------------------------------------------------------


// reverse :
for (int i=1; i<10; ++i) myvector.push_back(i);   // 1 2 3 4 5 6 7 8 9
std::reverse(myvector.begin(),myvector.end());    // 9 8 7 6 5 4 3 2 1
