BEGIN{
    highest_packet_id=0;
    count=0;
}

{
    action=$1;
    time=$2;
    node_1=$3;
    node_2=$4;
    packet_id=$12;
    if(packet_id>highest_packet_id) highest_packet_id=packet_id;
    if(start_time[packet_id]==0) start_time[packet_id]=time;
    if(action!="d"){
        if(action=="r"){
            end_time[packet_id]=time;
        }
    }else{
        end_time[packet_id]=-1;
    }
}
END{
    packet_duration;
    for(packet_id=0;packet_id<=highest_packet_id;packet_id++){
        start=start_time[packet_id];
        end=end_time[packet_id];
        if(start<end){
            count++;
            packet_duration+=end-start;
            }
    }
    printf("\n Average End-to-End Delay: %f\n", packet_duration/count);
}
