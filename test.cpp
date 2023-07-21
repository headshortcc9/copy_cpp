#include <iostream>
#include <memory>
#include <vector>
#include <xcb/xcb.h>
#include <map>
#include <atomic>

using namespace std;

atoms get_format_atoms(const format f) const {
    atoms atoms;
    if (f == text_format()) {
      atoms = get_text_format_atoms();
    }
    else {
      xcb_atom_t atom = get_format_atom(f);
      if (atom)
        atoms.push_back(atom);
    }
    return atoms;
}


int main() {
    typedef std::shared_ptr<std::vector<string>> buffer_ptr;
    std::map<xcb_atom_t, buffer_ptr> m_data;
    buffer_ptr shared_data_buf = std::make_shared<std::vector<string>> (10);

    std::shared_ptr<int> foo = std::make_shared<int> (10);

    string in="nghia";

    const char* buf=in.c_str();
    std::copy(buf,
              buf+5,
              shared_data_buf->begin());
    
    m_data[atom] = shared_data_buf;
    //cout<< shared_data_buf->pop_back() <<endl;
    cout<<*foo<<endl;
    //mutable std::map<xcb_atom_t, buffer_ptr> m_data;

}
  
