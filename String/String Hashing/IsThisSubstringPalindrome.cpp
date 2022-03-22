#define sz 500009
ll len;
string s;
const ll p = 41, mod = 1000003751;
ll p_pow[sz],fHash[sz],bHash[sz];

void Power()
{
    p_pow[0] = 1;
    for(ll i=1 ; i<=5e5+5 ; i++)
        p_pow[i] = (p_pow[i-1] * p)%mod;
}

void CalculateHash()
{
    fHash[0] = bHash[len+1] = 0LL;
    for(ll i=0 ; i<len ; i++){
        ll ch = (s[i] == '(')? 1 : 2;
        fHash[i+1] = (fHash[i] + (ch * p_pow[i+1])%mod)%mod;
    }

    for(ll i=len-1, j=0 ; i>=0 ; i-- , j++){
        ll ch = (s[i] == '(')? 1 : 2;
        bHash[i+1] = (bHash[i+2] + (ch * p_pow[j+1])%mod)%mod;
    }
}

bool isPalindrome(ll beg, ll ed)
{
    ll val1 = (fHash[ed] - fHash[beg-1] + mod)%mod;
    ll val2 = (bHash[beg] - bHash[ed+1] + mod)%mod;
    ll basepow1 = beg;
    ll basepow2 = len-ed+1;
    if(basepow1 >= basepow2)
        val2 = (val2 * p_pow[basepow1 - basepow2])%mod;
    else
        val1 = (val1 * p_pow[basepow2 - basepow1])%mod;

    return (val1 == val2);
}
