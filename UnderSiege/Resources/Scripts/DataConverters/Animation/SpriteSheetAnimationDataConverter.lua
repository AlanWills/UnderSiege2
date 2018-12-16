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
        
        spriteSheetAnimation:setSpriteSheetDimensions(converter:findAttribute("sprite_sheet_dimensions"):asUVec2())
        spriteSheetAnimation:setLooping(converter:findAttribute("looping"):asBool())
        spriteSheetAnimation:setPlayImmediately(converter:findAttribute("play_immediately"):asBool())
    end
})

-- Add move constructors
-- Delete all copy and assignment operators from data converters