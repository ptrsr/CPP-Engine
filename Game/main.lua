------------------------------------------------------------------------------------------------------------------------
--														main()
------------------------------------------------------------------------------------------------------------------------
function main()

	pi = 3.14159265359

	welcome = false
	played  = false
	gotbeer = false
	alcohol = 0
	ball    = 0
	
	glass = "beer"
	
	image("outside.png",0,0)
	
	if button("door.png", 420, 165) then
		visit("cafe")
	end
end

------------------------------------------------------------------------------------------------------------------------
--														cafe()
------------------------------------------------------------------------------------------------------------------------
function cafe()
	image("indoors.png", 0, 0)
	
	if welcome == false then
		image("comeDrink.png", 230, -40)
	end
	
	if button("barHitboxTest.png", 540, -90) then
		welcome = true
		visit("bar")
	end
	
	if button("barHitboxTest.png", 0, 100) then
		visit("table")
	end
end

------------------------------------------------------------------------------------------------------------------------
--														bar()
------------------------------------------------------------------------------------------------------------------------
function bar()
	image("bar.png", 0, 0)
	
	if gotbeer == false then
		image("onthehouse.png", 600, 200)
	end
	
	if glass == "empty" then
		image("empty.png", 300, 300)
		
		if button("glassHitBox.png", 135, 10) then
			glass = "red"
		end
		
		if button("glassHitBox.png", 215, 10) then
			glass = "blue"
		end
		
		if button("glassHitBox.png", 300, 10) then
			glass = "orange"
		end
		
		if button("glassHitBox.png", 380, 10) then
			glass = "purple"
		end
		
	end
	
	tempglass = glass
	
	if glass == "beer" then
		if button("beer.png", 300, 300) then
			glass = "empty"
			gotbeer = true
		end
	end
	
	if glass == "red" then
		if button("red.png", 300, 300) then
			glass = "empty"
		end
		
	elseif glass == "blue" then
		if button("blue.png", 300, 300) then
			glass = "empty"
		end
		
	elseif glass == "orange" then
		if button("orange.png", 300, 300) then
			glass = "empty"
		end
		
	elseif glass == "purple" then
		if button("purple.png", 300, 300) then
			glass = "empty"
		end
	end
	
	if tempglass ~= glass then
		alcohol = alcohol + 1
	end
	
	if alcohol == 1 then
		image("tipsy.png", 0, 0)
		
	elseif alcohol == 2 then
		image("drunk.png", 0, 0)
		
	elseif alcohol == 3 then
		image("wasted.png", 0, 0)
		
	elseif alcohol == 4 then
		visit("coma")
	end
	
	if button("back.png", 20, 20) then
		visit("cafe")
	end
end

------------------------------------------------------------------------------------------------------------------------
--														table()
------------------------------------------------------------------------------------------------------------------------
function table()
	image("table.png", 0, 0)
	
	if button("beaker.png", 390, 400) or
	button("beaker.png", 470, 400) or
	button("beaker.png", 550, 400) or
	button("ball.png", 480, 470) then
		visit("gamble")
	end
	
	if button("back.png", 20, 20) then
		visit("cafe")
	end
	
	if played == false then
		image("canyou.png", 550, 200)
	else
		image("ready.png", 550, 200)
	end
	
	time = 0;
end

------------------------------------------------------------------------------------------------------------------------
--														gamble()
------------------------------------------------------------------------------------------------------------------------
function gamble()
	image("table.png", 0, 0)
	
	found = false
	won = false
	b1 = 0
	b2 = 0
	b3 = 0
	
	time = time + 1
	
	image("beaker.png", 470 + math.sin(time / 10) * 100, 400)
	image("beaker.png", 470 + math.sin(time / 10 + pi) * 100, 400)
	image("beaker.png", 470 + math.sin(time / 10 + 1.5 * pi) * 100, 400)
	
	if button("screenhitbox.png", 0, 0) then
		visit("result")
	end
end

------------------------------------------------------------------------------------------------------------------------
--														result()
------------------------------------------------------------------------------------------------------------------------
function result()
	image("table.png", 0, 0)
	
	played = true
	
	height = 40 --The cup height after pressed
	
	beaker = time % 3

	if found == true then
		image("ball.png", 400 + beaker * 80, 450)
		
		if button("screenhitbox.png", 0, 0) then
			visit("table")
		end
	end
	
	if b1 == 0 then
		if button("beaker.png", 390, 400) then
			if beaker == 0 then
				found = true
			end
			b1 = height
		end
	else
		image("beaker.png", 390, 400 - b1)
	end
	
	if b2 == 0 then
		if button("beaker.png", 470, 400) then
			if beaker == 1 then
				found = true
			end
			b2 = height
		end
	else
		image("beaker.png", 470, 400 - b2)
	end
	
	if b3 == 0 then
		if button("beaker.png", 550, 400) then
			if beaker == 2 then
				found = true
			end
			b3 = height
		end
	else
		image("beaker.png", 550, 400 - b3)
	end
	
	if b1 + b2 + b3 == 0 then
		image("whichone.png", 550, 200)
		
	elseif b1 + b2 + b3 == height and found == true then
		won = true
		image("won.png", 550, 200)
		
	elseif b1 + b2 + b3 == height and found == false then
		image("toobad.png", 550, 200)
	
	elseif b1 + b2 + b3 > height and found == true then
		image("foundit.png", 550, 200)
	else
		image("nope.png", 550, 200)
	end
end


------------------------------------------------------------------------------------------------------------------------
--														coma()
------------------------------------------------------------------------------------------------------------------------
function coma()
	if button("coma.png", 0, 0) then
		visit("main")
	end
end
