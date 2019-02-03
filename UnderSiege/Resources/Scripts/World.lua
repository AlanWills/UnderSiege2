dimensions = "0.5%,0.5%"
ray_z_position = 1000

build = function(raycaster)
	raycaster:addSphere(
	    {
		    ["centre"] = "0,0,0",
		    ["radius"] = 100,
		    ["colour"] = "1,0,0"
	    }
    )

    raycaster:addSphere(
	    {
		    ["centre"] = "100,100,0",
		    ["radius"] = 50,
		    ["colour"] = "1,1,0"
	    }
    )
    
    raycaster:addSphere(
	    {
		    ["centre"] = "-500,-500,0",
		    ["radius"] = 500,
		    ["colour"] = "0,0,1"
	    }
    )

    raycaster:addPlane(
        {
            ["centre"] = "0,0,0",
            ["normal"] = "0,0,-1",
            ["colour"] = "0,1,0"
        }
    )
end