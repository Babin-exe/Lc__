// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/

class Solution {
    public List<String> removeSubfolders(String[] folder) {
        List<String> hehe = new ArrayList<>();
        Arrays.sort(folder); //O(n logn);
        hehe.add(folder[0]);
        for (int i = 1; i < folder.length; i++) { //O(folder length)
            String check = hehe.get(hehe.size() - 1) + "/";
            if (!folder[i].startsWith(check)) { //O(length of last value in hehe)
                hehe.add(folder[i]);
            }
        }
        return hehe;
    }
}
