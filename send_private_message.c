#include "mesh.h"
#include "que_packet_handle.h"
#include "neighbor_table.h"
usr_data_info_t UserDataC  = {0};
user_config_t usr ;
int main(){
    usr.destin = 0x0002;
    strcpy(usr.msg," Institute of Technology of Cambodia.");
    usr.mtypes = private_message_type;
    usr_send_config(&usr,UserDataC.data);
    // initialize nvs-storage
    nvs_memo_init();
    // initialize mesh-network.
    lora_mesh_init();
    // neib_to_user(&gg,UserDataC.data);
    UserDataC.usr_req_id = user_send_req; // define send request
    
    while (1)
    {
        mesh_handle(&UserDataC);  
    }   
    return 0;
}
