build = function(raycaster)
	raycaster:addSphere(
	    {
		    ["position"] = "0,0,0",
		    ["radius"] = 100,
		    ["colour"] = "1,0,0"
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