# define Node
class Node:
    def __init__(self, data: int = None) -> None:
        self.data = data
        self.next_node = None


# Singly Linked list class
class SinglyLinkedList:
    def __init__(self, n: int) -> None:
        self.n = n
        self.root: Node or None = None
        self.root = self.create_n_nodes(0)

    # Create N node recursively
    def create_n_nodes(self, i: int) -> Node:
        node = Node(i)
        if i == self.n - 1:
            return node
        else:
            node.next_node = self.create_n_nodes(i + 1)
            return node

    # Traverse and print  values of all nodes
    def traverse_and_display_node_vales(self) -> None:
        crawler: Node = self.root
        while crawler:
            print(f"data: {crawler.data}")
            crawler = crawler.next_node


if __name__ == '__main__':
    singlylinkedlist = SinglyLinkedList(10)
    singlylinkedlist.traverse_and_display_node_vales()
