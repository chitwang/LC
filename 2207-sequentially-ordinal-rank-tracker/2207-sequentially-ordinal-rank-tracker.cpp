#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class Temp> struct comparator {
    bool operator()( Temp a , Temp b){   
        if( a.first != b.first){
            return a.first > b.first;
        }
        return a.second < b.second;
    }
};

template <class Temp> using pbds =  tree<Temp, null_type, comparator<Temp>, rb_tree_tag, tree_order_statistics_node_update>;
class SORTracker {
public:
    pbds<pair<int, string>> st;
    int counter;
    SORTracker() {
        counter = 0;;
    }
    
    void add(string name, int score) {
        const pair<int, string> p = {score, name};
        st.insert(p);
    }
    
    string get() {
        auto it = *st.find_by_order(counter);
        counter++;
        return (it).second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */