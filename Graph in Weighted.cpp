#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#define NULL_VALUE -999999
#define INFINITY 999999
#define WHITE 1
#define GREY 2
#define BLACK 3
#define infinity 1000000007
#define MAX 100000
using namespace std;


class Queue
{
    int queueInitSize ;
    int queueMaxSize;
    int * data;
    int length;
    int front;
    int rear;
public:
    Queue();
    ~Queue();
    void enqueue(int item); //insert item in the queue
    int dequeue(); //returns the item according to FIFO
    bool empty(); //return true if Queue is empty
};

Queue::Queue()
{
    queueInitSize = 2 ;
    queueMaxSize = queueInitSize;
    data = new int[queueMaxSize] ; //allocate initial memory
    length = 0 ;
    front = 0;
    rear = 0;
}


void Queue::enqueue(int item)
{
	if (length == queueMaxSize)
	{
		int * tempData ;
		//allocate new memory space for tempList
		queueMaxSize = 2 * queueMaxSize ;
		tempData = new int[queueMaxSize] ;
		int i, j;
		j = 0;
		for( i = rear; i < length ; i++ )
		{
			tempData[j++] = data[i] ; //copy items from rear
		}
		for( i = 0; i < rear ; i++ )
		{
			tempData[j++] = data[i] ; //copy items before rear
		}
		rear = 0 ;
		front = length ;
		delete[] data ; //free the memory allocated before
		data = tempData ; //make list to point to new memory
	}

	data[front] = item ; //store new item
	front = (front + 1) % queueMaxSize ;
	length++ ;
}


bool Queue::empty()
{
	if(length == 0) return true ;
	else return false ;
}


int Queue::dequeue()
{
	if(length == 0) return NULL_VALUE ;
	int item = data[rear] ;
	rear = (rear + 1) % queueMaxSize ;
	length-- ;
	return item ;
}


Queue::~Queue()
{
    if(data) delete[] data; //deallocate memory
    data = 0; //set to NULL
}

//****************Queue class ends here************************

//****************Dynamic ArrayList class based************************
class ArrayList
{
	int * list;
	int length ;
	int listMaxSize ;
	int listInitSize ;
public:
	ArrayList() ;
	~ArrayList() ;
	int searchItem(int item) ;
    void insertItem(int item) ;
	void removeItem(int item) ;
	void removeItemAt(int item);
	int getItem(int position) ;
	int getLength();
	bool empty();
	void printList();
} ;


ArrayList::ArrayList()
{
	listInitSize = 2 ;
	listMaxSize = listInitSize ;
	list = new int[listMaxSize] ;
	length = 0 ;
}

void ArrayList::insertItem(int newitem)
{
	int * tempList ;
	if (length == listMaxSize)
	{
		//allocate new memory space for tempList
		listMaxSize = 2 * listMaxSize ;
		tempList = new int[listMaxSize] ;
		int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ; //copy all items from list to tempList
        }
        delete[] list ; //free the memory allocated before
        list = tempList ; //make list to point to new memory
	};

	list[length] = newitem ; //store new item
	length++ ;
}

int ArrayList::searchItem(int item)
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		if( list[i] == item ) return i;
	}
	return NULL_VALUE;
}

void ArrayList::removeItemAt(int position) //do not preserve order of items
{
	if ( position < 0 || position >= length ) return ; //nothing to remove
	list[position] = list[length-1] ;
	length-- ;
}


void ArrayList::removeItem(int item)
{
	int position;
	position = searchItem(item) ;
	if ( position == NULL_VALUE ) return ; //nothing to remove
	removeItemAt(position) ;
}


int ArrayList::getItem(int position)
{
	if(position < 0 || position >= length) return NULL_VALUE ;
	return list[position] ;
}

int ArrayList::getLength()
{
	return length ;
}

bool ArrayList::empty()
{
    if(length==0)return true;
    else return false;
}

void ArrayList::printList()
{
    int i;
    for(i=0;i<length;i++)
        printf("%d ", list[i]);
    printf("Current size: %d, current length: %d\n", listMaxSize, length);
}

ArrayList::~ArrayList()
{
    if(list) delete [] list;
    list = 0 ;
}

//******************ArrayList class ends here*************************

//******************Graph class starts here**************************
class Graph
{
	int nVertices, nEdges ;
	bool directed ;
	ArrayList  * adjList ;
	ArrayList *cost;

	int *color;
    int *parent;
    int *dist;
	//define other variables required for bfs such as color, parent, and dist
	//you must use pointers and dynamic allocation

public:
	Graph(bool dir = false);
	~Graph();
	void setnVertices(int n);
	void addEdge(int u, int v,int w);
	void removeEdge(int u, int v,int w);
	bool isEdge(int u, int v,int w);
    int getDegree(int u);
    void printAdjVertices(int u);
    bool hasCommonAdjacent(int u, int v);
    int getDist(int u, int v);
    void printGraph();
	void bfs(int source); //will run bfs in the graph
	void dfs(int source); //will run dfs in the graph
};


Graph::Graph(bool dir)
{
	nVertices = 0 ;
	nEdges = 0 ;
	adjList = 0 ;
	directed = dir ;
	cost=0;
	color=new int[nVertices];
    parent=new int[nVertices];
    dist=new int[nVertices];

	 //set direction of the graph
	//define other variables to be initialized
}

void Graph::setnVertices(int n)
{
	this->nVertices = n ;
	if(adjList!=0){
        delete[] cost;
        delete[] adjList; //delete previous list
	}
	adjList = new ArrayList[nVertices] ;

	cost = new ArrayList[nVertices] ;

}

void Graph::addEdge(int u, int v,int w)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices) return; //vertex out of range
    this->nEdges++ ;
	adjList[u].insertItem(v) ;
	cost[u].insertItem(w);
	if(!directed){
        adjList[v].insertItem(u) ;
        cost[v].insertItem(w);
	}
}

void Graph::removeEdge(int u, int v,int w)
{
    //write this function

    if(u<0 || v<0 || u>=nVertices || v>=nVertices) return; //vertex out of range
    this->nEdges-- ;
    adjList[u].removeItem(v);
    cost[u].removeItem(w);
    if(!directed){
        adjList[v].removeItem(u) ;
        cost[v].removeItem(w);
    }
}

bool Graph::isEdge(int u, int v,int w)
{
    //returns true if (u,v) is an edge, otherwise should return false
    int val=adjList[u].searchItem(v);
    if(val==NULL_VALUE)return false;
    //if(cost[u].getItem(val)==w)return true;

    return false;


}

int Graph::getDegree(int u)
{
    //returns the degree of vertex u

    int val=adjList[u].getLength();
    if(!directed)return 2*val;
    return val;

}

void Graph::printAdjVertices(int u)
{
    //prints all adjacent vertices of a vertex u

    adjList[u].printList();
}

bool Graph::hasCommonAdjacent(int u, int v)
{
    //returns true if vertices u and v have common adjacent vertices
    int val;
    for(int i=0;i<adjList[u].getLength();i++){
        val=adjList[v].searchItem(adjList[u].getItem(i));
        if(val!=NULL_VALUE)return true;
    }
    return false;

}

void Graph::bfs(int source)
{
    //complete this function
    //initialize BFS variables
    //int len=Graph.getLength();
    color=new int[nVertices];
    parent=new int[nVertices];
    dist=new int[nVertices];

    for(int i=0; i<nVertices; i++)
    {
        color[i] = WHITE ;
        parent[i] = -1 ;
        dist[i] = INFINITY ;
    }
    Queue q ;
    color[source] = GREY;
    dist[source] = 0 ;
    q.enqueue(source) ;
    int val;
    while( !q.empty() )
    {
        //complete this part

        int u=q.dequeue();
        for(int i=0;i<adjList[u].getLength();i++){
            val=adjList[u].getItem(i);
            if(color[val]==WHITE){
                color[val]=GREY;
                dist[val]=dist[u]+1;
                q.enqueue(val) ;
            }
        }
    }
    return;
}

int Graph::getDist(int u, int v)
{
    //returns the shortest path distance from u to v
    //must call bfs using u as the source vertex, then use distance array to find the distance
    bfs(u);
    int val=dist[v];
    return val;
}

void Graph::printGraph()
{
    printf("\nNumber of vertices: %d, Number of edges: %d\n", nVertices, nEdges);
    for(int i=0;i<nVertices;i++)
    {
        printf("%d:", i);
        for(int j=0; j<adjList[i].getLength();j++)
        {
            printf(" (%d %d)", adjList[i].getItem(j),cost[i].getItem(j));
        }
        printf("\n");
    }
}

Graph::~Graph()
{
    //write your destructor here
    /*for(int i=0;i<nVertices;i++){
        free(adjList[i]);
    }*/
    //}
    free(color);
    free(dist);
    free(parent);

}


//**********************Graph class ends here******************************


//******main function to test your code*************************
int main(void)
{
    int n;
    Graph g;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    g.setnVertices(n);

    while(1)
    {
        printf("1. Add edge. \n");
        printf("2.removeEdge(). 3.isEdge() 4.getDegree() 5. Print Graph  6. Print adjacent vertices 7.has common adjacent \n");
        printf("8. Run BFS 9.Find dist 10.Graph Destructor 11.Exit\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int u, v,w;
            scanf("%d%d%d", &u, &v,&w);
            g.addEdge(u, v,w);
        }
        /*else if(ch==2)
        {
            int u,v,w,
            //scanf("%d%d",&u,&v);
            cin>>u>>v>>w;
            g.removeEdge(u,v,w);
        }*/
        else if(ch==3)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            bool ans=g.isEdge(u,v,w);
            printf("%d\n",ans);
        }
        else if(ch==4)
        {
            int u;
            scanf("%d",&u);
            int ans=g.getDegree(u);
            printf("%d\n",ans);
        }
        else if(ch==5)
        {
            g.printGraph();
        }
        else if(ch==6){
            int u;
            scanf("%d",&u);
            g.printAdjVertices(u);
        }
        else if(ch==7){
            int u,v;
            scanf("%d%d",&u,&v);
            printf("%d\n",g.hasCommonAdjacent(u,v));
            //cout<<g.hasCommonAdjacent(u,v)<<endl;
        }
        else if(ch==8){
            int u;
            scanf("%d",&u);
            g.bfs(u);
        }
        else if(ch==9){
            int u,v;
            scanf("%d%d",&u,&v);
            printf("%d\n",g.getDist(u,v));
            //cout<<g.getDist(u,v)<<endl;
        }
        else if(ch==10){
            g.~Graph();
        }
        else if(ch==11){
            break;
        }
    }


}
