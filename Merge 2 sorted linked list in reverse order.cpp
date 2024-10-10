# Node class for linked list
class ListNode:
    def __init__(self, value=0, next=None):
        self.value = value
        self.next = next

# Function to merge two sorted linked lists in non-increasing order
def merge_in_reverse(l1, l2):
    dummy = ListNode()  # Dummy node to act as the head of the result list
    tail = dummy        # Tail pointer to build the result list

    # Traverse both lists and compare their nodes
    while l1 and l2:
        if l1.value > l2.value:
            next_node = l1
            l1 = l1.next
        else:
            next_node = l2
            l2 = l2.next
        
        # Insert the larger node at the head of the result list
        next_node.next = tail.next
        tail.next = next_node

    # Append any remaining nodes from l1 or l2
    while l1:
        next_node = l1
        l1 = l1.next
        next_node.next = tail.next
        tail.next = next_node

    while l2:
        next_node = l2
        l2 = l2.next
        next_node.next = tail.next
        tail.next = next_node

    return dummy.next  # Return the new head (skipping the dummy node)

# Helper function to print linked list
def print_list(node):
    while node:
        print(node.value, end=" -> ")
        node = node.next
    print("None")

# Example usage:
# Create linked list 1: 1 -> 3 -> 5
l1 = ListNode(1)
l1.next = ListNode(3)
l1.next.next = ListNode(5)

# Create linked list 2: 2 -> 4 -> 6
l2 = ListNode(2)
l2.next = ListNode(4)
l2.next.next = ListNode(6)

# Merge the lists in non-increasing order
merged_list = merge_in_reverse(l1, l2)

# Print the merged list
print("Merged List in Non-Increasing Order:")
print_list(merged_list)
