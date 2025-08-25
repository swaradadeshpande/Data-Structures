#include <iostream>
#include <string>
using namespace std;

class load_balancer {
    int n_servers;  
    int hash_server[100];
    string hash_server_str[100];   
public:
    load_balancer(int n) {
        n_servers = n;
        for(int i=0; i<n; i++) {
            hash_server[i] = 0;   
        }
    }
    int hash_request(int requestID) {
        return requestID % n_servers;
    }
    int hash_request(string ip) {
        int sum = 0, num = 0;
        for(int i = 0; ip[i] != '\0'; i++) {
            char c = ip[i];
            if(c == '.') {
                sum += num;
                num = 0;
            } else {
                num = num * 10 + (c - '0');
            }
        }
        sum += num;
        return sum % n_servers;
    }

    void assign_request(int requestID) {
        int hash_val = hash_request(requestID);

        if(hash_server[hash_val] == 0) {
            hash_server[hash_val] = requestID;
        } else {
            for(int i = hash_val; i < n_servers-1; i++) {
                hash_val=hash_val+1;
                if(hash_server[hash_val] == 0) {
                    hash_server[hash_val] = requestID;
                    break;
                }
            }
            if(hash_val == n_servers) {
                for(int i = 0; i < n_servers-1; i++) {
                    hash_val=hash_val+1;
                    if(hash_server[i] == 0) {
                        hash_server[i] = requestID;
                        break;
                    }
                }
            }
        }
        cout << "Request " << requestID 
             << " -> Server " << hash_val << endl;
    }

    void assign_request(string ip) {
        int hash_val = hash_request(ip);

        if(hash_server_str[hash_val] == "") {
            hash_server_str[hash_val] = ip;
        } else {
            for(int i = hash_val; i < n_servers-1; i++) {
                hash_val=hash_val+1;
                if(hash_server_str[hash_val] == "") {
                    hash_server_str[hash_val] = ip;
                    break;
                }
            }
            if(hash_val == n_servers) {
                for(int i = 0; i < n_servers-1; i++) {
                    hash_val=hash_val+1;
                    if(hash_server_str[i] == "") {
                        hash_server_str[i] = ip;
                        break;
                    }
                }
            }
        }
        cout << "Request from " << ip 
             << " -> Server " << hash_val << endl;
    }

   void displayServers() {
        cout << "\nServer Table for IDs: ";
        for (int i = 0; i < n_servers; i++) {
            cout << hash_server[i] << " ";
        }
        cout << "\nServer Table for IPs: ";
        for (int i = 0; i < n_servers; i++) {
            if (hash_server_str[i] == "")
                cout << "[empty] ";
            else
                cout << hash_server_str[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    int n, r, choice;
    cout << "Enter number of servers: ";
    cin >> n;
    cout << "Enter number of requests: ";
    cin >> r;
    load_balancer lb(n);

    cout << "Choose input type (1 = IDs, 2 = IPs): ";
    cin >> choice;

    if(choice == 1) {
        for(int i=0; i<r; i++) {
            int id;
            cout << "Enter Request ID number "<<i+1<< ": ";
            cin >> id;
            lb.assign_request(id);
        }
    } else {
        for(int i=0; i<r; i++) {
            string ip;
            cout << "Enter IP number "<<i+1<< ": ";
            cin >> ip;
            lb.assign_request(ip);
        }
    }

    lb.displayServers();

    return 0;
}
