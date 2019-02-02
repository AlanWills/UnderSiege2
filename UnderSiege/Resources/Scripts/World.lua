dimensions = "0.5%,0.5%"

build = function(raycaster)
	raycaster:addSphere(
	    {
		    ["position"] = "0,0,0",
		    ["radius"] = 100,
		    ["colour"] = "1,0,0"
	    }
    )

    raycaster:addSphere(
	    {
		    ["position"] = "100,100,0",
		    ["radius"] = 50,
		    ["colour"] = "1,1,0"
	    }
    )
    
    raycaster:addSphere(
	    {
		    ["position"] = "-500,-500,0",
		    ["radius"] = 500,
		    ["colour"] = "0,0,1"
	    }
    )

    raycaster:addPlane(
        {
            ["position"] = "0,0,0",
            ["normal"] = "0,0,-1",
            ["colour"] = "0,1,0"
        }
    )
end