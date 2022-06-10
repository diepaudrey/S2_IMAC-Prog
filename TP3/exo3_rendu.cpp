#include <iostream>

using namespace std;
int COUNT = 10;

struct Node
{    
    Node* left;
    Node* right;
    int value;

    //to visualize the tree
    void print2DUtil(Node* root, int space){
        // Base case
        if (root== NULL)
            return;
    
        // Increase distance between levels
        space += COUNT;
    
        // Process right child first
        print2DUtil(root->right,space);
    
        // Print current node after space
        // count
        cout<<endl;
        for (int i = COUNT; i < space; i++)
            cout<<" ";
        cout<<root->value<<"\n";
    
        // Process left child
        print2DUtil(root->left,space);
    }
 
    // Wrapper over print2DUtil()
    void print2D()
    {
        // Pass initial space count as 0
        print2DUtil(this, 0);
        
    }


    //TP
    void initNode(int value)
    {
        // init initial node without children
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }

	void insertNumber(int value) {
        // create a new node and insert it in right or left child
        struct Node* newNode = new Node();
        newNode->value = value;

        //we suppose there is a root
        if(this->value > value){
            if(this->left == nullptr){

                //create a node
                this->left = newNode;
                newNode->left = nullptr;
                newNode->right = nullptr;
                
                
            }
            this->left->insertNumber(value);
        }

        if(this->value < value){
            if(this->right == nullptr){

                //create a node
                this->right = newNode;
                newNode->left = nullptr;
                newNode->right = nullptr;
            }
            this->right->insertNumber(value);
        }
        



    }

	int height()   const {
        // should return the maximum height between left child and
        // right child +1 for itself. If there is no child, return
        // just 1   

        int countRight;
        int countLeft;

        if(this->left == nullptr){
            countLeft = 0;
        }
        else{
            countLeft = this->left->height();
        }

        if(this->right == nullptr){
            countRight = 0;
        }
        else{
            countRight =  this->right->height();
            
        }

        return max(countRight, countLeft) +1 ;

    }

	int nodesCount() const {
        // should return the sum of nodes within left child and
        // right child +1 for itself. If there is no child, return
        // just 1

        int countRight;
        int countLeft;

        if(this->left == nullptr){
            countLeft = 0;
        }
        else{
            countLeft = this->left->nodesCount();
        }

        if(this->right == nullptr){
            countRight = 0;
        }
        else{
            countRight =  this->right->nodesCount();
            
        }

        return countRight + countLeft +1 ;

        
	}

	bool isLeaf() const {
        // return True if the node is a leaf (it has no children)
        if(this->left != nullptr || this->right != nullptr){
            return false;
        }
        else{
            return true;
        }
	}

	void allLeaves(Node* leaves[], int& leavesCount) {
        // fill leaves array with all leaves of this tree
        if(this->left == nullptr){
           if(this->isLeaf()==true){
                cout << "   " << this->value << endl;
                leaves[leavesCount] = this;
                leavesCount ++;
                return;
            }
        }
        else{
            this->left->allLeaves(leaves,leavesCount);
        }

        if(this->right == nullptr){
            if(this->isLeaf()==true){
                cout << this->value << endl;  //just to visualize
                leaves[leavesCount] = this;
                leavesCount ++;
                return;
            }
        }
        else{
            this->right->allLeaves(leaves, leavesCount);
        }
        

	}

	void inorderTravel(Node* nodes[], int& nodesCount) {
        // fill nodes array with all nodes with inorder travel
        if(this->left != nullptr){
            this->left->inorderTravel(nodes,nodesCount);
        }
        
        nodes[nodesCount] = this;
        cout << " " << this->value << endl;  //just to visualize
        nodesCount ++;

        if(this->right != nullptr){
            this->right->inorderTravel(nodes,nodesCount);
        }


	}

	void preorderTravel(Node* nodes[], int& nodesCount) {
        // fill nodes array with all nodes with preorder travel

        //root
        nodes[nodesCount] = this;
        cout << " " << this->value << endl;  //just to visualize
        nodesCount ++;

        //left
        if(this->left != nullptr){
            this->left->preorderTravel(nodes,nodesCount);
        }
        
        //right
        if(this->right != nullptr){
            this->right->preorderTravel(nodes,nodesCount);
        }

	}

	void postorderTravel(Node* nodes[], int& nodesCount) {
        // fill nodes array with all nodes with postorder travel


        //left
        if(this->left != nullptr){
            this->left->postorderTravel(nodes,nodesCount);
        }
        
        //right
        if(this->right != nullptr){
            this->right->postorderTravel(nodes,nodesCount);
        }

        //root
        nodes[nodesCount] = this;
        cout << " " << this->value << endl;  //just to visualize
        nodesCount ++;

        
	}

	Node* find(int value) {
        if(this->value == value){
            return this;
        }
        else{
            //go left subtree
            if(value < this->value){
                this->left->find(value);

            }
            //go right subtree
            else{
                this->right->find(value);
            }
           
        }
	
	return nullptr;
        
	}

};


int main(){
    //initializing the tree
        Node a_node;
        a_node.initNode(5); 
        a_node.insertNumber(8);
        a_node.insertNumber(3);
        a_node.insertNumber(2);
        a_node.insertNumber(4);

    //print the binary tree
        a_node.print2D();


    //height
        int heightTree = a_node.height();
        cout << "height of the tree : " << heightTree << endl;


    //nodes count
        int nodesCount = a_node.nodesCount();
        cout << "Numbers of nodes : " << nodesCount << endl;

    
    //isLeaf
        if(a_node.isLeaf()==true){
            cout << "isLeaf returned True " << endl;
        }
        else{
            cout << "isLeaf returned False " << endl;
        }

    //allLeaves
        Node* leaves[5];
        int leavesCount = 0;

        cout << "All leaves : " << endl;
        a_node.allLeaves(leaves, leavesCount);
        
    

    //Travels, just test one by one
        Node* allNodes[nodesCount];
        int nodeIni = 0;

        // cout << "With inorder travel : " << endl; 
        // a_node.inorderTravel(allNodes,nodeIni);

        // cout << "With preorder travel : " << endl; 
        // a_node.preorderTravel(allNodes,nodeIni);

        cout << "With postorder travel : " << endl; 
        a_node.postorderTravel(allNodes,nodeIni);



    //Node find 
        int toFind = 3;
        Node* find = a_node.find(toFind);
        cout << find->value << endl;
        cout << find << endl;


    return 0;
}
