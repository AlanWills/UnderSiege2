registerComponentDataConverter("SpriteSheetAnimation", 
{
    ["attributes"] = 
    {
        ["SpriteSheetDimensions"] = 
        {
            ["Name"] = "sprite_sheet_dimensions",
            ["Type"] = "unsigned vec2",
            ["Default Value"] = "1, 1",
            ["Is Required"] = true,
            ["Is Reference"] = true
        }
    },
    
    ["elements"] = {
    }
})

-- Test move constructor - could be fun
-- Also, need to reset data converters somehow after they have converted, since we are not
-- creating a new instance every time we are doing conversion
-- Think about this - would it be better to have some sort of cloning instantiation behaviour instead?
-- Or should we be clever and have one which we reset?
-- Do we store the default value in the attributes/elements, because if we do, we're golden (except for derived classes doing custom behaviour?)
-- Is custom behaviour even a thing?