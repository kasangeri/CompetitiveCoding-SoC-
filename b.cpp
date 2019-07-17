#include<bits/stdc++.h>
using namespace std;

int main()
{
 set<int> V;
 for(int i=0;i<10;i++) V.insert(i);
 //V.erase(V.find(0));
 cout<<*(V.begin());
 if(V.find(4)==V.end()) cout<<"yooo";
}


	print "Second Example - Odd number of transaction Merkel Tree"
	Jae_Tree = Jae_MerkTree()
	transaction = ['a','b','c','d','e']
	Jae_Tree.listoftransaction = transaction
	Jae_Tree.create_tree()
	past_transaction = Jae_Tree.Get_past_transacion()
	print 'Final root of the tree : ',Jae_Tree.Get_Root_leaf()
	print(json.dumps(past_transaction, indent=4))
	print "-" * 50 

	# i) Actual Use Case
	print "Final Example - Actuall use case of the Merkle Tree"

	# i-1) Declare a transaction - the ground truth
	ground_truth_Tree = Jae_MerkTree()
	ground_truth_transaction = ['a','b','c','d','e']
	ground_truth_Tree.listoftransaction = ground_truth_transaction
	ground_truth_Tree.create_tree()
	ground_truth_past_transaction = ground_truth_Tree.Get_past_transacion()
	ground_truth_root = ground_truth_Tree.Get_Root_leaf()

	# i-2) Declare a tampered transaction
	tampered_Tree = Jae_MerkTree()
	tampered_Tree_transaction = ['a','b','c','d','f']
	tampered_Tree.listoftransaction = tampered_Tree_transaction
	tampered_Tree.create_tree()
	tampered_Tree_past_transaction = tampered_Tree.Get_past_transacion()
	tampered_Tree_root = tampered_Tree.Get_Root_leaf()

	# i-3) The three company share all of the transaction 
	print 'Company A - my final transaction hash : ',ground_truth_root
	print 'Company B - my final transaction hash : ',ground_truth_root
	print 'Company C - my final transaction hash : ',tampered_Tree_root

	# i-4) Print out all of the past transaction
	print "\n\nGround Truth past Transaction "
	print(json.dumps(ground_truth_past_transaction, indent=4))
	
	print "\n\nTamper Truth past Transaction "
	print(json.dumps(tampered_Tree_past_transaction, indent=4))

