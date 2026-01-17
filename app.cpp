#include <iostream>
#include <vector>
#include <utility>

class User {
    private:
        std::string password = "";
    public:
        std::string username = "";
        void sign_up() {
            std::cout<<"Enter a username: ";
            std::cin>>username;
            std::cout<<"Enter a password: ";
            std::cin>>password;
            while(password.size() == 0) {
                std::cout<<"the password field is required!\nplease try again: ";
                std::cin>>password;
            }
            std::cout<<"welcome, "<<username<<" you're account has been created.\n";
        }
        
        std::string name_input;
        std::string password_input;

        std::string sign_in() {
            std::cout<<"Enter your username: ";
            std::cin>>name_input;
            std::cout<<"Enter your password: ";
            std::cin>>password_input;

            if(name_input != username || password_input != password) {
                while(name_input != username || password_input != password) {
                    std::cout<<"Username or Password was incorrect, Please try again: ";
                    std::cin>>name_input>>password_input;
                }
            }
            return password_input;        
        }
};

std::pair<std::string, std::string> make_list() {
    User user1;
    user1.sign_up();
    std::string m = user1.username;
    
    std::string n = user1.sign_in();
    return {m, n}; 
}


int main() {
    std::vector<std::string> user_list;
    std::vector<std::string> password_list;
    bool active = true;

    while(active) {
        auto [first, second] = make_list();
        user_list.push_back(first); 
        password_list.push_back(second);
    
        int hello;
        std::cout<<"would u like to add another user (1 = yes, 0 = no) ? ";
        std::cin>>hello;
        switch(hello) {
        case 0:
            active = false;
            break;
        case 1:
            active = true;
            break;
        default:
            std::cout<<"invalid number";
            active = false;
        }
    }

    for(int i = 0; i < size(user_list); i++) {
        std::cout<< user_list[i] << " " << password_list[i] << "\n";
    }

    std::cout<<"goodbye!\n";
}
