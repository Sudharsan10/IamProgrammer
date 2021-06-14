//
// Created by Sudo on 6/9/2021.
//

#include <iostream>
#include "singlylinkedlist.h"

void LL::SinglyLinkedList::create_n_nodes(int n) {
    std::shared_ptr<LL::Node> crawler{this->root};
    for(auto i = 0; i<n; i++){
        crawler->set_data(i+1);
        crawler->next_ = std::make_shared<LL::Node>();
        crawler = crawler->next_;
    }
}

void LL::SinglyLinkedList::traverseAndPrint() const {
    std::shared_ptr<LL::Node> crawler{this->root};
    while(true){
        if(crawler -> get_data() == 0) break;
        std::cout << "data: " << crawler->get_data() << std::endl;
        crawler = crawler->next_;
    }
}