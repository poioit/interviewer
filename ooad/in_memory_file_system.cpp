
//https://leetcode.com/problems/design-in-memory-file-system/description/
// ls: may be a file path, not directory path

class FileSystem {
    enum Type {
        DIR,
        FILE
    };
    class Entry {
        string name;
        Type type;
        map<string,Entry*> entries;
        string content;
    public: 
        Entry(string n, Type t) {
            type = t;
            name = n;
        }
        
        bool isFile() {
            return type == FILE;
        }
        
        bool isDir() {
            return type == DIR;
        }
        
        string getName() {
            return name;
        }
        
        string getContent() {
            return content;
        }
        
        bool setContent(string c) {
            if (isFile()) {
                content = c;
                return true;
            }
            return false;
        }
        
        bool appendContent(string c) {
            if (isFile()) {
                content += c;
                return true;
            }
            return false;
        }
        
        void addEntry(Entry *e) {
            if (e)
                entries[e->name] = e;
        }
        bool contains(string name) {
            if (isFile())
                return false;
            return entries.count(name) > 0;
        }
        Entry* getEntry(string name) {
            if (contains(name)) {
                return entries[name];
            }
            return NULL; 
        }
        
        vector<Entry*> getEntries() {
            vector<Entry*> rst;
            for (auto p : entries) {
                rst.push_back(p.second);
            }
            return rst;
        }
    };
    
    Entry *root;
    
    vector<string> split(string s) {
        vector<string> rst;
        for (int i = 0 ; i < s.size(); i++) {
            if (s[i] != '/') {
                size_t end = s.find('/', i);
                // cout << "end: " << end << endl;
                if (end != string::npos) {
                    rst.push_back(s.substr(i, end-i));
                    i = end;
                }
                else {
                    string tmp = s.substr(i);
                    if (tmp.size() > 0)
                        rst.push_back(tmp);
                    break;
                }
            }
        }
        // cout << s << endl;
        // for (string s : rst) {
        //     cout << "split: " << s << " ";
        // }
        // cout << endl;
        return rst;
    }
    
    Entry *getTailEntry(string path) {
        if (path.size() == 0) {
            return NULL;
        }
        Entry *cur = root;
        vector<string> toks = split(path);
        for (auto s : toks) {
            if (cur->contains(s)) {
                cur = cur->getEntry(s);
            }
            else {
                return NULL;
            }
        }
        return cur;
    }
    
 public:
    FileSystem() {
        root = new Entry("", DIR);
    }
    
    vector<string> ls(string path) {
        vector<string> rst;
        Entry *cur = getTailEntry(path);
        if (cur->isFile()) {
            rst.push_back(cur->getName());
        }
        else {
            for (Entry *e : cur->getEntries()) {
                rst.push_back(e->getName());
            }
        }
        return rst;
    }
    
    Entry *create(string path, Type type) {
        vector<string> strs = split(path);
        Entry *cur = root;
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            // cout << "create: " << s << endl;
            if (cur->contains(s) == false) {
                // the last entry may be a file/directory
                if (i == strs.size() - 1) {
                    cur->addEntry(new Entry(s, type));
                }
                else {
                    cur->addEntry(new Entry(s, DIR));
                }
            }
            cur = cur->getEntry(s);
        }
        return cur;
    }
    
    void mkdir(string path) {
        create(path, DIR);
    }
    
    void addContentToFile(string filePath, string content) {
        Entry *e = create(filePath, FILE);
        // cout << filePath << endl;
        // cout << e->getName() << endl;
        e->appendContent(content);
    }
    
    string readContentFromFile(string filePath) {
        Entry *cur = getTailEntry(filePath);
        return cur ? cur->getContent() : "";
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * vector<string> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * string param_4 = obj.readContentFromFile(filePath);
 */