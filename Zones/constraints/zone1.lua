  -- zone1.lua

zone1 = { 
    
    startX = 8,
    startY = 415,

    waterRangeStartY = 0,
    waterRangeEndY = 488,
    
    waterRangeStartX =  317,
    waterRangeEndX = 348,

    brideStartX = 311,
    brideStartY = 160,
    bridgeEndY = 178,
    
    
    x = 150,
    y = 150,
    size = 3,
    -- -- every block of 3 represents one tree
    -- -- greater than less than less than
    -- coords = {60, 120, 525}
    -- 9 - >=
    -- 8 - >
    -- 7 - <=
    -- 6 - <
    cord1 = "9X60",
    cord2 = "7X120",
    cord3 = "7Y525",
    title = "Bridge"
}

return bridge
