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
        },
        ["Looping"] = 
        {
            ["Name"] = "looping",
            ["Type"] = "bool",
            ["Default Value"] = "true",
            ["Is Required"] = false,
            ["Is Reference"] = false
        },
        ["PlayImmediately"] = 
        {
            ["Name"]= "play_immediately",
            ["Type"] = "bool",
            ["Default Value"] = "true",
            ["Is Required"] = false,
            ["Is Reference"] = false
        }
    },

    ["onSetGameObject"] = function(converter, component)

    end
})