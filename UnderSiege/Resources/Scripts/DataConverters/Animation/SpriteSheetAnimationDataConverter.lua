LuaComponentDataConverter.register("Animation", 
{
    ["Attributes"] = 
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

    ["SetValues"] = function(converter, component)
        local animator = component:asAnimator()
        
        animator:setSpriteSheetDimensions(converter:findAttribute("sprite_sheet_dimensions"):asUVec2())
        animator:setLooping(converter:findAttribute("looping"):asBool())
        animator:setPlayImmediately(converter:findAttribute("play_immediately"):asBool())
    end
})