public Node flattenList(Node head2) {
	if(head2 == null)
		return head2;
	Node curr = head2;
	List<node> queue = new LinkedList<node>();
	while(curr != null)	{
		while(curr.next != null)	{
			if(curr.child != null)	{
				queue.add(curr.child);
			}
			curr = curr.next;
		}
		if(curr.next == null && curr.child != null)	{
			queue.add(curr.child);
		}
		if(queue.size() != 0)	{
			curr.next = queue.remove(0);
		}
		curr = curr.next;
	}
	return head2;
}
