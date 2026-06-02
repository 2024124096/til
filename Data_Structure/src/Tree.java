public class Tree {
    private Node root;
    private void doInorderTraversal(Node r) {
        if (r == null) return;

        doInorderTraversal(r.left);
        visit(r);
        doInorderTraversal(r.right);
    }

    // 사용자용 재귀 시작 버튼
        // public 메서드 = 사용자가 부름
        // private 재귀 메서드 = 실제 작업
    public void inorderTraversal() {
        doInorderTraversal(root);
    }
}