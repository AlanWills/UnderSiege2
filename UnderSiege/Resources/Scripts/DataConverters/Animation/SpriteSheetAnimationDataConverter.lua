LuaComponentDataConverter.register("SpriteSheetAnimation", 
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
            ["Default Value"] = "true"
        },
        ["PlayImmediately"] = 
        {
            ["Name"]= "play_immediately",
            ["Type"] = "bool",
            ["Default Value"] = "true"
        }
    },

    ["doSetValues"] = function(converter, component)
        local spriteSheetAnimation = component:asSpriteSheetAnimation()
        local playImmediately = converter:findAttribute("play_immediately")
        
        spriteSheetAnimation:setPlayImmediately(playImmediately:asBool())
        --component:setSpriteSheetDimensions(4, 4);
    end
})

-- Add move constructors
-- Delete all copy and assignment operators from data converters