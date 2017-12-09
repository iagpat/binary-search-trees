
#ifndef NODE_H
#define NODE_H
namespace cop3530 {

    template<typename key, typename value>
    struct node {
        key node_key;
        value node_value;
        node* right = nullptr;
        node* left = nullptr;

        node(key key_case, value value_case) {
            node_key = key_case;
            node_value = value_case;
            right = nullptr;
            left = nullptr;
        }


    };
}


#endif /* NODE_H */

