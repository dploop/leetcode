impl Solution {
    pub fn get_decimal_value(head: Option<Box<ListNode>>) -> i32 {
        let (mut result, mut l) = (0, head);
        while let Some(t) = l {
            result = result * 2 + t.val;
            l = t.next;
        }
        return result;
    }
}
