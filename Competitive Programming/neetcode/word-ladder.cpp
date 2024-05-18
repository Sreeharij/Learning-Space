//Below solution complexity is O(n^2*m) where n is length of wordlist and m is max_length of a single word
class Solution {
public:
    bool single_difference(string& first,string& second,int word_length){
        int diff_count=0;
        for(int i=0;i<word_length;i++){
            if(first[i] != second[i]){
                diff_count++;
            }
        }
        if(diff_count != 1) return false;
        return true;
    }

    int get_shortest_distance(string& beginWord,string& endWord,unordered_map<string,vector<string>>& graph){
        if(graph.find(endWord) == graph.end()){
            return 0;
        }
        unordered_map<string,int> visited;
        for(auto x: graph){
            visited[x.first] = -1;
        }
        queue<string> q;
        q.push(beginWord);
        visited[beginWord] = 1;

        while(!q.empty()){
            string current_word = q.front();
            q.pop();
            for(auto word: graph[current_word]){
                if(visited[word] == -1){
                    visited[word] = visited[current_word] + 1;
                    q.push(word);
                }
            }
        }
        if(visited[endWord] == -1) return 0;
        return visited[endWord];
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int shortest_length = 0;
        unordered_map<string,vector<string>> graph;
        int word_length = beginWord.size();
        int wordlist_size = wordList.size();
        for(int i=0;i<wordlist_size;i++){
            graph[wordList[i]] = vector<string>();
            for(int j=0;j<wordlist_size;j++){
                if(i==j) continue;
                if(single_difference(wordList[i],wordList[j],word_length)){
                    graph[wordList[i]].push_back(wordList[j]); 
                }
            }
        }
        
        graph[beginWord] = vector<string>();
        for(auto word: wordList){
            if(single_difference(beginWord,word,word_length)){
                graph[beginWord].push_back(word);
                graph[word].push_back(beginWord);
            }
        }
        shortest_length = get_shortest_distance(beginWord,endWord,graph);
        return shortest_length;
    }
};