class Solution {
    int toNextWord(const string& path, int i) {
        while (i < path.size() && path[i] == '/') {
            ++i;
        }

        return i;
    }

    int createWord(const string& path, string& buf, int i) {
        while (i < path.size() && path[i] != '/') {
            buf.push_back(path[i]);
            ++i;
        }

        return i;
    }

    string createPath(const vector<string>& pathStack) {
        if (pathStack.size() == 0) {
            return "/";
        }

        string simpPath = "";

        for (const string& dirOrFile: pathStack) {
            simpPath.append("/");
            simpPath.append(dirOrFile);
        }

        return simpPath;
    }
public:
    string simplifyPath(string path) {
        vector<string> pathStack;

        int i = toNextWord(path, 0);

        while (i < path.size()) {
            string word = "";
            i = createWord(path, word, i);

            if (word == ".." && pathStack.size() != 0) {
                pathStack.pop_back();
            } else if (word != "." && word != "..") {
                pathStack.push_back(word);
            }

            i = toNextWord(path, i);
        }

        return createPath(pathStack);
    }
};