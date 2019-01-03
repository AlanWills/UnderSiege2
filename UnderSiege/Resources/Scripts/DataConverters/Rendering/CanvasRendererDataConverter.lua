LuaComponentDataConverter.register("CanvasRenderer", 
{
    ["Attributes"] = 
    {
        ["ProjectionMode"] = 
        {
            ["Name"] = "projection_mode",
            ["Type"] = "string",
            ["Default Value"] = "Orthographic",
        },
        ["CanvasDimensions"] = 
        {
            ["Name"] = "dimensions",
            ["Type"] = "vec2",
            ["Default Value"] = "1%,1%",
			["Is Reference"] = true
        }
    },

    ["SetValues"] = function(converter, component)
        local canvasRenderer = component:asCanvasRenderer()
        
        canvasRenderer:setProjectionMode(converter:findAttribute("projection_mode"):asString())
        canvasRenderer:setDimensions(converter:findAttribute("dimensions"):asVec2())
    end
})