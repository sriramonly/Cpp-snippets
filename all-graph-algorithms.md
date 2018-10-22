Welcome to the new episode of [PrinceOfPersia](/profile/PrinceOfPersia "Candidate Master PrinceOfPersia") presents: Fun with algorithms ;)

You can find all the definitions here in the book "Introduction to graph theory", Douglas.B West. Important graph algorithms :

DFS
---

The most useful graph algorithms are search algorithms. DFS (Depth First Search) is one of them.

While running DFS, we assign colors to the vertices (initially white). Algorithm itself is really simple :

    dfs (v):
            color[v] = gray
            for u in adj[v]:
                    if color[u] == white
                            then dfs(u)
            color[v] = black

Black color here is not used, but you can use it sometimes.

Time complexity : _O_(_n_ + _m_).

#### DFS tree

DFS tree is a rooted tree that is built like this :

    let T be a new tree
    dfs (v):
            color[v] = gray
            for u in adj[v]:
                    if color[u] == white
                            then dfs(u) and par[u] = v (in T)
    
            color[v] = black

**Lemma:** There is no cross edges, it means if there is an edge between _v_ and _u_, then _v_ = _par_\[_u_\] or _u_ = _par_\[_v_\].

#### Starting time, finishing time

Starting time of a vertex is the time we enter it (the order we enter it) and its finishing time is the time we leave it. Calculating these are easy :

    TIME = 0
    dfs (v):
            st[v] = TIME ++
            color[v] = gray
            for u in adj[v]:
                    if color[u] == white
                            then dfs(u)
            color[v] = black
            ft[v] = TIME // or we can use TIME ++

It is useable in specially data structure problems (convert the tree into an array).

**Lemma:** If we run _dfs_(_root_) in a rooted tree, then _v_ is an ancestor of _u_ if and only if _st__v_ ≤ _st__u_ ≤ _ft__u_ ≤ _ft__v_ .

So, given arrays _st_ and _ft_ we can rebuild the tree.

#### Finding cut edges

The code below works properly because the lemma above (first lemma):

    h[root] = 0
    par[v] = -1
    dfs (v):
            d[v] = h[v]
            color[v] = gray
            for u in adj[v]:
                    if color[u] == white
                            then par[u] = v and dfs(u) and d[v] = min(d[v], d[u])
                            if d[u] > h[v]
                                    then the edge v-u is a cut edge
                    else if u != par[v])
                            then d[v] = min(d[v], h[u])
            color[v] = black

In this code, _h_\[_v_\] =  height of vertex _v_ in the DFS tree and _d_\[_v_\] = _min_(_h_\[_w_\] where there is at least vertex _u_ in subtree of _v_ in the DFS tree where there is an edge between _u_ and _w_).

#### Finding cut vertices

The code below works properly because the lemma above (first lemma):

    h[root] = 0
    par[v] = -1
    dfs (v):
            d[v] = h[v]
            color[v] = gray
            for u in adj[v]:
                    if color[u] == white
                            then par[u] = v and dfs(u) and d[v] = min(d[v], d[u])
                            if d[u] >= h[v] and (v != root or number_of_children(v) > 1)
                                    then the edge v is a cut vertex
                    else if u != par[v])
                            then d[v] = min(d[v], h[u])
            color[v] = black

In this code, _h_\[_v_\] =  height of vertex _v_ in the DFS tree and _d_\[_v_\] = _min_(_h_\[_w_\] where there is at least vertex _u_ in subtree of _v_ in the DFS tree where there is an edge between _u_ and _w_).

#### Finding Eulerian tours

It is quite like DFS, with a little change :

    vector E
    dfs (v):
            color[v] = gray
            for u in adj[v]:
                    erase the edge v-u and dfs(u)
            color[v] = black
            push v at the end of e

_e_ is the answer.

Problems: [500D - New Year Santa Network](/contest/500/problem/D "Good Bye 2014"), [475B - Strongly Connected City](/contest/475/problem/B "Bayan 2015 Contest Warm Up")

BFS
---

BFS is another search algorithm (Breadth First Search). It is usually used to calculate the distances from a vertex _v_ to all other vertices in unweighted graphs.

Code :

            BFS(v):
                    for each vertex i
                            do d[i] = inf
                    d[v] = 0
                    queue q
                    q.push(v)
                    while q is not empty
                            u = q.front()
                            q.pop()
                            for each w in adj[u]
                                    if d[w] == inf
                                            then d[w] = d[u] + 1, q.push(w)

Distance of vertex _u_ from _v_ is _d_\[_u_\].

Time complexity : _O_(_n_ + _m_).

#### BFS tree

BFS tree is a rooted tree that is built like this :

    let T be a new tree
            BFS(v):
                    for each vertex i
                            do d[i] = inf
                    d[v] = 0
                    queue q
                    q.push(v)
                    while q is not empty
                            u = q.front()
                            q.pop()
                            for each w in adj[u]
                                    if d[w] == inf
                                            then d[w] = d[u] + 1, q.push(w) and par[w] = u (in T)

SCC
---

The most useful and fast-coding algorithm for finding SCCs is Kosaraju.

In this algorithm, first of all we run DFS on the graph and sort the vertices in decreasing of their finishing time (we can use a stack).

Then, we start from the vertex with the greatest finishing time, and for each vertex _v_ that is not yet in any SCC, do : for each _u_ that _v_ is reachable by _u_ and _u_ is not yet in any SCC, put it in the SCC of vertex _v_. The code is quite simple.

Problems: [CAPCITY](http://www.spoj.com/problems/CAPCITY/), [BOTTOM](http://www.spoj.com/problems/BOTTOM/)

Shortest path
=============

Shortest path algorithms are algorithms to find some shortest paths in directed or undirected graphs.

Dijkstra
--------

This algorithm is a single source shortest path (from one source to any other vertices). Pay attention that you can't have edges with negative weight.

Pseudo code :

    dijkstra(v) :
            d[i] = inf for each vertex i
            d[v] = 0
            s = new empty set
            while s.size() < n
                    x = inf
                    u = -1
                    for each i in V-s //V is the set of vertices
                            if x >= d[i]
                                    then x = d[i], u = i
                    insert u into s
                    // The process from now is called Relaxing
                    for each i in adj[u]
                            d[i] = min(d[i], d[u] + w(u,i))
                            

There are two different implementations for this. Both are useful (C++11).

One) _O_(_n_2)

    int mark[MAXN];
    void dijkstra(int v){
    	fill(d,d + n, inf);
    	fill(mark, mark + n, false);
    	d[v] = 0;
    	int u;
    	while(true){
    		int x = inf;
    		u = -1;
    		for(int i = 0;i < n;i ++)
    			if(!mark[i] and x >= d[i])
    				x = d[i], u = i;
    		if(u == -1)	break;
    		mark[u] = true;
    		for(auto p : adj[u]) //adj[v][i] = pair(vertex, weight)
    			if(d[p.first] > d[u] + p.second)
    				d[p.first] = d[u] + p.second;
    	}
    }

Two) ![](/predownloaded/78/cb/78cbd240f0f43a574eca1a110cf408f9808f17ab.png)

1) Using `std :: set` :

    void dijkstra(int v){
    	fill(d,d + n, inf);
    	d[v] = 0;
    	int u;
    	set<pair<int,int> > s;
    	s.insert({d[v], v});
    	while(!s.empty()){
    		u = s.begin() -> second;
    		s.erase(s.begin());
    		for(auto p : adj[u]) //adj[v][i] = pair(vertex, weight)
    			if(d[p.first] > d[u] + p.second){
    				s.erase({d[p.first], p.first});
    				d[p.first] = d[u] + p.second;
    				s.insert({d[p.first], p.first});
    			}
    	}
    }

2) Using `std :: priority_queue` (better):

    bool mark[MAXN];
    void dijkstra(int v){
    	fill(d,d + n, inf);
    	fill(mark, mark + n, false);
    	d[v] = 0;
    	int u;
    	priority_queue<pair<int,int>,vector<pair<int,int> >, less<pair<int,int> > > pq;
    	pq.push({d[v], v});
    	while(!pq.empty()){
    		u = pq.top().second;
    		pq.pop();
    		if(mark[u])
    			continue;
    		mark[u] = true;
    		for(auto p : adj[u]) //adj[v][i] = pair(vertex, weight)
    			if(d[p.first] > d[u] + p.second){
    				d[p.first] = d[u] + p.second;
    				pq.push({d[p.first], p.first});
    			}
    	}
    }

Problem: [ShortestPath Query](//codeforces.com/gym/100571/problem/D)

Floyd-Warshall
--------------

Floyd-Warshal algorithm is an all-pairs shortest path algorithm using dynamic programming.

It is too simple and undrestandable :

    Floyd-Warshal()
    	d[v][u] = inf for each pair (v,u)
    	d[v][v] = 0 for each vertex v
    	for k = 1 to n
    		for i = 1 to n
    			for j = 1 to n
    				d[i][j] = min(d[i][j], d[i][k] + d[k][j])

Time complexity : _O_(_n_3).

Bellman-Ford
------------

Bellman-Ford is an algorithm for single source shortest path where edges can be negative (but if there is a cycle with negative weight, then this problem will be NP).

The main idea is to relax all the edges exactly _n_ - 1 times (read relaxation above in dijkstra). You can prove this algorithm using induction.

If in the _n_ - _th_ step, we relax an edge, then we have a negative cycle (this is if and only if).

Code :

    Bellman-Ford(int v)
    	d[i] = inf for each vertex i
    	d[v] = 0
    	for step = 1 to n
    		for all edges like e
    			i = e.first // first end
    			j = e.second // second end
    			w = e.weight
    			if d[j] > d[i] + w
    				if step == n
    					then return "Negative cycle found"
    				d[j] = d[i] + w
    

Time complexity : _O_(_nm_).

SPFA
----

SPFA (Shortest Path Faster Algorithm) is a fast and simple algorithm (single source) that its complexity is not calculated yet. But if _m_ = _O_(_n_2) it's better to use the first implementation of Dijkstra.

The origin of this algorithm is unknown. It's said that at first Chinese coders used it in programming contests.

Its code looks like the combination of Dijkstra and BFS :

    SPFA(v):
    	d[i] = inf for each vertex i
    	d[v] = 0
    	queue q
    	q.push(v)
    	while q is not empty
    		u = q.front()
    		q.pop()
    		for each i in adj[u]
    			if d[i] > d[u] + w(u,i)
    				then d[i] = d[u] + w(u,i)
    				if i is not in q
    					then q.push(i)

Time complexity : _Unknown_!.

MST
===

MST = Minimum Spanning Tree :) (if you don't know what it is, google it).

Best MST algorithms :

Kruskal
-------

In this algorithm, first we sort the edges in ascending order of their weight in an array of edges.

Then in order of the sorted array, we add ech edge if and only if after adding it there won't be any cycle (check it using DSU).

Code :

    Kruskal()
    	solve all edges in ascending order of their weight in an array e
    	ans = 0
    	for i = 1 to m
    		v = e.first
    		u = e.second
    		w = e.weight
    		if merge(v,u) // there will be no cycle
    			then ans += w

Time complexity : ![](/predownloaded/ee/d7/eed729b1a4d27042b962a6e751911990d39898bb.png).

Prim
----

In this approach, we act like Dijkstra. We have a set of vertices _S_, in each step we add the nearest vertex to _S_, in _S_ (distance of _v_ from ![](/predownloaded/97/01/9701a520f9b09305c264a9c7262f5b44a74f0740.png) where _weight_(_i_, _j_) is the weight of the edge from _i_ to _j_) .

So, pseudo code will be like this:

    Prim()
    	S = new empty set
    	for i = 1 to n
    		d[i] = inf
    	while S.size() < n
    		x = inf
    		v = -1
    		for each i in V - S // V is the set of vertices
    			if x >= d[v]
    				then x = d[v], v = i
    		d[v] = 0
    		S.insert(v)
    		for each u in adj[v]
    			do d[u] = min(d[u], w(v,u))

C++ code:

One) _O_(_n_2)

    bool mark[MAXN];
    void prim(){
    	fill(d, d + n, inf);
    	fill(mark, mark + n, false);
    	int x,v;
    	while(true){
    		x = inf;
    		v = -1;
    		for(int i = 0;i < n;i ++)
    			if(!mark[i] and x >= d[i])
    				x = d[i], v = i;
    		if(v == -1)
    			break;
    		d[v] = 0;
    		mark[v] = true;
    		for(auto p : adj[v]){ //adj[v][i] = pair(vertex, weight)
    			int u = p.first, w = p.second;
    			d[u] = min(d[u], w);
    		}
    	}
    }

Two) ![](/predownloaded/5f/ff/5fff706ccec9c6485dd07d40e394ba3e06265b71.png)

    void prim(){
    	fill(d, d + n, inf);
    	set<pair<int,int> > s;
    	for(int i = 0;i < n;i ++)
    		s.insert({d[i],i});
    	int v;
    	while(!s.empty()){
    		v = s.begin() -> second;
    		s.erase(s.begin());
    		for(auto p : adj[v]){
    			int u = p.first, w = p.second;
    			if(d[u] > w){
    				s.erase({d[u], u});
    				d[u] = w;
    				s.insert({d[u], u});
    			}
    		}
    	}
    }

As Dijkstra you can use `std :: priority_queue` instead of `std :: set`.

Maximum Flow
------------

You can read all about maximum flow [here](http://en.wikipedia.org/wiki/Maximum_flow_problem).

I only wanna put the source code here (EdmondsKarp):

    algorithm EdmondsKarp
        input:
            C[1..n, 1..n] (Capacity matrix)
            E[1..n, 1..?] (Neighbour lists)
            s             (Source)
            t             (Sink)
        output:
            f             (Value of maximum flow)
            F             (A matrix giving a legal flow with the maximum value)
        f := 0 (Initial flow is zero)
        F := array(1..n, 1..n) (Residual capacity from u to v is C[u,v] - F[u,v])
        forever
            m, P := BreadthFirstSearch(C, E, s, t, F)
            if m = 0
                break
            f := f + m
            (Backtrack search, and write flow)
            v := t
            while v ≠ s
                u := P[v]
                F[u,v] := F[u,v] + m
                F[v,u] := F[v,u] - m
                v := u
        return (f, F)
    	
    	
    	
    algorithm BreadthFirstSearch
        input:
            C, E, s, t, F
        output:
            M[t]          (Capacity of path found)
            P             (Parent table)
        P := array(1..n)
        for u in 1..n
            P[u] := -1
        P[s] := -2 (make sure source is not rediscovered)
        M := array(1..n) (Capacity of found path to node)
        M[s] := ∞
        Q := queue()
        Q.offer(s)
        while Q.size() > 0
            u := Q.poll()
            for v in E[u]
                (If there is available capacity, and v is not seen before in search)
                if C[u,v] - F[u,v] > 0 and P[v] = -1
                    P[v] := u
                    M[v] := min(M[u], C[u,v] - F[u,v])
                    if v ≠ t
                        Q.offer(v)
                    else
                        return M[t], P
        return 0, P
    	
    	
    	
    

EdmondsKarp pseudo code using Adjacency nodes:

    algorithm EdmondsKarp
        input:
            graph (Graph with list of Adjacency nodes with capacities,flow,reverse and destinations)
            s             (Source)
            t             (Sink)
        output:
            flow             (Value of maximum flow)
        flow := 0 (Initial flow to zero)
        q := array(1..n) (Initialize q to graph length)
        while true
            qt := 0            (Variable to iterate over all the corresponding edges for a source)
            q[qt++] := s    (initialize source array)
            pred := array(q.length)    (Initialize predecessor List with the graph length)
            for qh=0;qh < qt && pred[t] == null
                cur := q[qh]
                for (graph[cur]) (Iterate over list of Edges)
                     Edge[] e :=  graph[cur]  (Each edge should be associated with Capacity)
                     if pred[e.t] == null && e.cap > e.f
                        pred[e.t] := e
                        q[qt++] : = e.t
            if pred[t] == null
                break
            int df := MAX VALUE (Initialize to max integer value)
            for u = t; u != s; u = pred[u].s
                df := min(df, pred[u].cap - pred[u].f)
            for u = t; u != s; u = pred[u].s
                pred[u].f  := pred[u].f + df
                pEdge := array(PredEdge)
                pEdge := graph[pred[u].t]
                pEdge[pred[u].rev].f := pEdge[pred[u].rev].f - df;
            flow := flow + df
        return flow

#### Dinic's algorithm

Here is Dinic's algorithm as you wanted.

Input: A network _G_ = ((_V_, _E_), _c_, _s_, _t_).

Output: A max _s_ - _t_ flow.

    1.set f(e) = 0 for each e in E
    2.Construct G_L from G_f of G. if dist(t) == inf, then stop and output f 
    3.Find a blocking flow fp in G_L
    4.Augment flow f by fp  and go back to step 2.

Time complexity : ![](/predownloaded/39/9b/399b8dc87c41658dd7f74dff7a2ad00ec441ba8f.png).

**Theorem:** Maximum flow = minimum cut.

### Maximum Matching in bipartite graphs

Maximum matching in bipartite graphs is solvable also by maximum flow like below :

Add two vertices _S_, _T_ to the graph, every edge from _X_ to _Y_ (graph parts) has capacity 1, add an edge from _S_ with capacity 1 to every vertex in _X_, add an edge from every vertex in _Y_ with capacity 1 to _T_.

Finally, answer = maximum matching from _S_ to _T_ .

But it can be done really easier using DFS.

As, you know, a bipartite matching is the maximum matching if and only if there is no augmenting path (read Introduction to graph theory).

The code below finds a augmenting path:

    bool dfs(int v){// v is in X, it reaturns true if and only if there is an augmenting path starting from v
    	if(mark[v])
    		return false;
    	mark[v] = true;
    	for(auto &u : adj[v])
    		if(match[u] == -1 or dfs(match[u])) // match[i] = the vertex i is matched with in the current matching, initially -1
    			return match[v] = u, match[u] = v, true;
    	return false;
    }

An easy way to solve the problem is:

    for(int i = 0;i < n;i ++)if(match[i] == -1){
    	memset(mark, false, sizeof mark);
    	dfs(i);
    }

But there is a faster way:

    while(true){
    	memset(mark, false, sizeof mark);
    	bool fnd = false;
    	for(int i = 0;i < n;i ++) if(match[i] == -1 && !mark[i])
    		fnd |= dfs(i);
    	if(!fnd)
    		break;
    }

In both cases, time complexity = _O_(_nm_).

Problem: [498C - Array and Operations](/contest/498/problem/C "Codeforces Round 284 (Div. 1)")

Trees
=====

Trees are the most important graphs.

In the last lectures we talked about segment trees on trees and heavy-light decomposition.

Partial sum on trees
--------------------

We can also use partial sum on trees.

Example: Having a rooted tree, each vertex has a value (initially 0), each query gives you numbers _v_ and _u_ (_v_ is an ancestor of _u_) and asks you to increase the value of all vertices in the path from _u_ to _v_ by 1.

So, we have an array _p_, and for each query, we increase _p_\[_u_\] by 1 and decrease _p_\[_par_\[_v_\]\] by 1. The we run this (like a normal partial sum):

    void dfs(int v){
    	for(auto u : adj[v])
    		if(u - par[v])
    			dfs(u), p[v] += p[u];
    }

DSU on trees
------------

We can use DSU on a rooted tree (not tree DSUs, DSUs like vectors).

For example, in each node, we have a vector, all nodes in its subtree (this can be used only for offline queries, because we may have to delete it for memory usage).

Here again we use DSU technique, we will have a vector _V_ for every node. When we want to have _V_\[_v_\] we should merge the vectors of its children. I mean if its children are _u_1, _u_2, ..., _u__k_ where _V_\[_u_1\]._size_() ≤ _V_\[_u_2\]._size_() ≤ ... ≤ _V_\[_u__k_\]._size_(), we will put all elements from _V_\[_u__i_\] for every 1 ≤ _i_ < _k_, in _V_\[_k_\] and then, _V_\[_v_\] = _V_\[_u__k_\].

Using this trick, time complexity will be ![](/predownloaded/78/cb/78cbd240f0f43a574eca1a110cf408f9808f17ab.png).

C++ example (it's a little complicated) :

    typedef vector<int> vi;
    vi *V[MAXN];
    void dfs(int v, int par = -1){
    	int mx = 0, chl = -1;
    	for(auto u : adj[v])if(par - u){
    		dfs(u,v);
    		if(mx < V[u]->size()){
    			mx = V[u]->size();
    			chl = u;
    		}
    	}
    	for(auto u : adj[v])if(par - u and chl - u){
    		for(auto a : *V[u])
    			V[chl]->push_back(a);
    		delete V[u];
    	}
    	if(chl + 1)
    		V[v] = V[chl];
    	else{
    		V[v] = new vi;
    		V[v]->push_back(v);
    	}
    }

LCA
---

LCA of two vertices in a rooted tree, is their lowest common ancestor.

There are so many algorithms for this, I will discuss the important ones.

Each algorithm has complexities  < _O_(_f_(_n_)), _O_(_g_(_n_)) > , it means that this algorithm's preprocess is _O_(_f_(_n_)) and answering a query is _O_(_g_(_n_)) .

In all algorithms, _h_\[_v_\] =  height of vertex _v_.

**One) Brute force  < _O_(_n_), _O_(_n_) > **

The simplest approach. We go up enough to achieve the goal.

Preproccess :

    void dfs(int v,int p = -1){
    	if(par + 1)
    		h[v] = h[p] + 1;
    	par[v] = p;
    	for(auto u : adj[v])	if(p - u)
    		dfs(u,v);
    }

Query :

    int LCA(int v,int u){
    	if(v == u)
    		return v;
    	if(h[v] < h[u])
    		swap(v,u);
    	return LCA(par[v], u);
    }

**Two) SQRT decomposition ![](/predownloaded/26/43/264322f3af5fdebf0993ddd2e0d08b0fa5964630.png)** 

I talked about SQRT decomposition in the first lecture.

Here, we will cut the tree into ![](/predownloaded/4f/74/4f7439f1176d1dea4c4cc372f2dd0c8ff0db5b54.png) (_H_ = height of the tree), starting from 0, _k_ - _th_ of them contains all vertices with _h_ in interval ![](/predownloaded/0a/82/0a8296bb5244cfb025f41731083a86f3969d2f41.png).

Also, for each vertex _v_ in _k_ - _th_ piece, we store _r_\[_v_\] that is, its lowest ancestor in the piece number _k_ - 1.

Preprocess:

    void dfs(int v,int p = -1){
    	if(par + 1)
    		h[v] = h[p] + 1;
    	par[v] = p;
    	if(h[v] % SQRT == 0)
    		r[v] = p;
    	else
    		r[v] = r[p];
    	for(auto u : adj[v])	if(p - u)
    		dfs(u,v);
    }

Query:

    int LCA(int v,int u){
    	if(v == u)
    		return v;
    	if(h[v] < h[u])
    		swap(v,u);
    	if(h[v] == h[u])
    		return (r[v] == r[u] ? LCA(par[v], par[u]) : LCA(r[v], r[u]));
    	if(h[v] - h[u] < SQRT)
    		return LCA(par[v], u);
    	return LCA(r[v], u);
    }

**Three) Sparse table ![](/predownloaded/75/b7/75b73098fefd4e07e225bfe409b665e9d668ac0c.png)** 

Let's introduce you an order of tree vertices, [haas](/profile/haas "International master haas") and I named it _Euler_ _order_. It is like DFS order, but every time we enter a vertex, we write it's number down (even when we come from a child to this node in DFS).

Code for calculate this :

    vector<int> euler;
    void dfs(int v,int p = -1){
    	euler.push_back(v);
    	for(auto u : adj[v])	if(p - u)
    		dfs(u,v), euler.push_back(v);
    }

If we have a `vector<pair<int,int> >` instead of this and push `{h[v], v}` in the vector, and the first time `{h[v], v}` is appeared is _s_\[_v_\] and _s_\[_v_\] < _s_\[_u_\] then _LCA_(_v_, _u_) = (_min__i_ = _s_\[_v_\]_s_\[_u_\]_euler_\[_i_\])._second_.

For this propose we can use RMQ problem, and the best algorithm for that, is to use Sparse table.

**Four) Something like Sparse table :) ![](/predownloaded/69/a0/69a04fe8b9591fe427ce8df428e15a87075870f8.png)** 

This is the most useful and simple (among fast algorithms) algorithm.

For each vector _v_ and number _i_, we store its 2_i_\-th ancestor. This can be done in ![](/predownloaded/78/cb/78cbd240f0f43a574eca1a110cf408f9808f17ab.png). Then, for each query, we find the lowest ancestors of them which are in the same height, but different (read the source code for understanding).

Preprocess:

    int par[MAXN][MAXLOG]; // initially all -1
    void dfs(int v,int p = -1){
    	par[v][0] = p;
    	if(p + 1)
    		h[v] = h[p] + 1;
    	for(int i = 1;i < MAXLOG;i ++)
    		if(par[v][i-1] + 1)
    			par[v][i] = par[par[v][i-1]][i-1];
    	for(auto u : adj[v])	if(p - u)
    		dfs(u,v);
    }

Query:

    int LCA(int v,int u){
    	if(h[v] < h[u])
    		swap(v,u);
    	for(int i = MAXLOG - 1;i >= 0;i --)
    		if(par[v][i] + 1 and h[par[v][i]] >= h[u])
    			v = par[v][i];
    	// now h[v] = h[u]
    	if(v == u)
    		return v;
    	for(int i = MAXLOG - 1;i >= 0;i --)
    		if(par[v][i] - par[u][i])
    			v = par[v][i], u = par[u][i];
    	return par[v][0];
    }

**Five) Advance RMQ  < _O_(_n_), _O_(1) > **

In the third approach, we said that LCA can be solved by RMQ.

When you look at the vector _euler_ you see that for each _i_ that 1 ≤ _i_ < _euler_._size_(), |_euler_\[_i_\]._first_ - _euler_\[_i_ + 1\]._first_| = 1.

So, we can convert the _euler_ from its size(we consider its size is _n_ + 1) into a binary sequence of length _n_ (if _euler_\[_i_\]._first_ - _euler_\[_i_ + 1\]._first_ = 1 we put 1 otherwise 0).

So, we have to solve the problem on a binary sequence _A_ .

To solve this restricted version of the problem we need to partition _A_ into blocks of size ![](/predownloaded/27/a0/27a0c37a27f0ddf092e89ac7e7dcac2b7cf8d5bc.png). Let _A_'\[_i_\] be the minimum value for the _i_ - _th_ block in _A_ and _B_\[_i_\] be the position of this minimum value in _A_. Both _A_ and _B_ are ![](/predownloaded/c6/f4/c6f489bbb188f10ecfe9b94569d494906a4e6552.png) long. Now, we preprocess _A_' using the Sparse Table algorithm described in lecture 1. This will take ![](/predownloaded/05/c1/05c11b9ae431219c5d81e13bf361b2d0c55237fe.png) time and space. After this preprocessing we can make queries that span over several blocks in _O_(1). It remains now to show how the in-block queries can be made. Note that the length of a block is ![](/predownloaded/27/a0/27a0c37a27f0ddf092e89ac7e7dcac2b7cf8d5bc.png), which is quite small. Also, note that _A_ is a binary array. The total number of binary arrays of size _l_ is ![](/predownloaded/68/b2/68b2f5f5f9c70b75df33b78d584fada783d1e3ed.png). So, for each binary block of size _l_ we need to lock up in a table _P_ the value for _RMQ_ between every pair of indices. This can be trivially computed in ![](/predownloaded/9a/1c/9a1c05761df95a83805878bed53725df220b0d53.png) time and space. To index table _P_, preprocess the type of each block in _A_ and store it in array ![](/predownloaded/68/db/68db49e667b9b77123b60481cf7c501874f40334.png). The block type is a binary number obtained by replacing  - 1 with 0 and  + 1 with 1 (as described above).

Now, to answer _RMQA_(_i_, _j_) we have two cases:

*   _i_ and _j_ are in the same block, so we use the value computed in _P_ and _T_
*   _i_ and _j_ are in different blocks, so we compute three values: the minimum from _i_ to the end of _i_'s block using _P_ and _T_, the minimum of all blocks between _i_'s and _j_'s block using precomputed queries on _A_' and the minimum from the beginning of _j_'s block to _j_, again using _T_ and _P_; finally return the position where the overall minimum is using the three values you just computed.

**Six) Tarjan's algorithm _O_(_na_(_n_)) (_a_(_n_) is the inverse ackermann function)**

Tarjan's algorithm is offline; that is, unlike other lowest common ancestor algorithms, it requires that all pairs of nodes for which the lowest common ancestor is desired must be specified in advance. The simplest version of the algorithm uses the union-find data structure, which unlike other lowest common ancestor data structures can take more than constant time per operation when the number of pairs of nodes is similar in magnitude to the number of nodes. A later refinement by Gabow & Tarjan (1983) speeds the algorithm up to linear time.

The pseudocode below determines the lowest common ancestor of each pair in _P_, given the root _r_ of a tree in which the children of node _n_ are in the set _n_.children. For this offline algorithm, the set _P_ must be specified in advance. It uses the _MakeSet_, _Find_, and _Union_ functions of a disjoint-set forest. _MakeSet_(_u_) removes _u_ to a singleton set, _Find_(_u_) returns the standard representative of the set containing _u_, and _Union_(_u_, _v_) merges the set containing _u_ with the set containing _v_. _TarjanOLCA_(_r_) is first called on the root _r_.

     function TarjanOLCA(u)
         MakeSet(u);
         u.ancestor := u;
         for each v in u.children do
             TarjanOLCA(v);
             Union(u,v);
             Find(u).ancestor := u;
         u.colour := black;
         for each v such that {u,v} in P do
             if v.colour == black
                 print "Tarjan's Lowest Common Ancestor of " + u +
                       " and " + v + " is " + Find(v).ancestor + ".";

Each node is initially white, and is colored black after it and all its children have been visited. The lowest common ancestor of the pair {_u_, _v_} is available as _Find_(_v_).ancestor immediately (and only immediately) after _u_ is colored black, provided _v_ is already black. Otherwise, it will be available later as _Find_(_u_)._ancestor_, immediately after _v_ is colored black.

     function MakeSet(x)
         x.parent := x
         x.rank   := 0
     
     function Union(x, y)
         xRoot := Find(x)
         yRoot := Find(y)
         if xRoot.rank > yRoot.rank
             yRoot.parent := xRoot
         else if xRoot.rank < yRoot.rank
             xRoot.parent := yRoot
         else if xRoot != yRoot
             yRoot.parent := xRoot
             xRoot.rank := xRoot.rank + 1
      
     function Find(x)
         if x.parent == x
            return x
         else
            x.parent := Find(x.parent)
            return x.parent
