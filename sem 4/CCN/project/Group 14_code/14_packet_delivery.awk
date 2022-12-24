BEGIN{
    receive=0
    drop=0
    total=0
    ratio=0
}
{
    if($1=="r"&&$4==2)
    {
        receive++;
    }
    if($1=="d"&&$4==1)
    {
        drop++;
    }
}
END{
    total=receive+drop
    ratio=(receive/total)*100
    
    printf("\n Total Packet Sent: %d", total)
    printf("\n Packet Delivery Ratio: %f", ratio)
    printf("\n Total Packet Dropped: %d", drop)
    printf("\n");
}