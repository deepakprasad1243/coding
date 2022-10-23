#include <bits/stdc++.h> 
using namespace std;
#define ll long long int
#define pb push_back
#define rsz resize
#define endl '\n'
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define pi  pair<int,int>
#define x first
#define y second
#define p(x,y) pair<x, y>
#define tll tuple<ll,ll,ll>
#define v(x) vector<x>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const ll mxN = 2e5+5;
const ll mod = 1e9 + 7;
const ll N = 2e5+5;
const ll oo = 1e15;
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define repf(x,start,end,k) for(auto x = start;x<=end;x+=k)
#define repb(x,start,end,k) for(auto x = start;x>=end;x-=k)

ll arr[N],seg[4*N];

void build(int node,int st,int en){
    if(st == en){
        // left node ,string the single array element
        seg[node] = arr[st];
        return;
    }

    int mid = (st+en)/2;

    // recursively call for left child
    build(2*node,st,mid);

    // recursively call for right child
    build(2*node+1,mid+1,en);

    // Updating the parent with the values of the left and right child.
    seg[node] = seg[2*node]+seg[2*node+1];
}

void update(int node, int st, int en, int l, int r, int val){

	if(lazy[node] != 0)  // if node is lazy then update it
	{
		seg[node] += (en-st+1)*lazy[node];
		
		if(st != en) // if its children exist
		{
            // mark both child lazy
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}

        // No longer lazy
		lazy[node] = 0;  
	}
	if( (en < l) || (st > r) ) // case 1
	{
		return ;	
	}	
	if(st >= l && en <= r) { // case 2

		seg[node] += (en-st+1)*val;  
		if(st != en)
		{
			lazy[2*node] += val; // mark its children lazy
			lazy[2*node+1] += val; 
		}
		return;
	}

    // case 3
	int mid = (st+en)/2;	

    // recursively call for updating left child
	update(2*node, st, mid, l, r, val);      
    // recursively call for updating right child
	update(2*node+1, mid+1, en, l, r, val);

    // Updating the parent with the values of the left and right child.
	seg[node] = (seg[2*node] + seg[2*node+1]); 
}

int query(int node, int st, int en, int l, int r)
{
	/*If node is lazy, update it*/
	if(lazy[node] != 0){

		seg[node] += (en-st+1)*lazy[node];
		if(st != en) //Check if the child exist
		{
            // mark bothe the child lazy
			lazy[2*node] += lazy[node];   
			lazy[2*node+1] += lazy[node]; 
		}
        // no longer lazy
		lazy[node]=0;
	}
	// case 1
	if(en<l || st>r){
		return 0;
	}

	// case 2
	if((l <= st) && (en <= r )){
		return seg[node];
	}
	int mid = (st+en)/2;	

    //query left child 
	ll q1 = query(2*node, st, mid, l, r); 

    // query right child
	ll q2 = query(2*node+1, mid+1, end, l, r); 

	return (q1 + q2);	
}

void update(ll node,ll st,ll en,ll val,ll idx){
    if(st == en){
        seg[node] = val;
        arr[idx] = val;
        return;
    }

    ll mid = (st + en)/2;

    if(idx<=mid) update(2*node,st,mid,val,idx);
    else update(2*node+1,mid+1,en,val,idx);

    seg[node] = seg[2*node]+seg[2*node+1];
}

ll query(ll node,ll st,ll en,ll l,ll r){
    if(l > en || r < st) return 0;

    if(l<=st && r >=en) return seg[node];

    ll mid = (st+en)/2;
    return query(2*node,st,mid,l,r)+query(2*node+1,mid+1,en,l,r);
}

int main(){
    FAST;

    ll n,q,l,r,type;
    cin >> n >> q;

    rep(i,1,n+1)
        cin >> arr[i];

    build(1,1,n);

    while(q--){
        cin >> type >> l >> r;

        if(type == 1)
            update(1,1,n,r,l);
        else cout << query(1,1,n,l,r) << endl;
    }

}