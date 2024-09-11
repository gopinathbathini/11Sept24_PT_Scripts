Action()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Accept-Language", 
		"en-GB,en;q=0.9");

	lr_start_transaction("Pets_Launch");
	
	web_url("pets.shaft.com", 
		"URL=http://pets.shaft.com/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Pets_Launch",LR_AUTO);

	/*Possible OAUTH authorization was detected. It is recommended to correlate the authorization parameters.*/

	lr_think_time(31);

	lr_start_transaction("Pets_FindOwner");

	web_url("Find owners", 
		"URL=http://pets.shaft.com/owners/find", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://pets.shaft.com/", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Pets_FindOwner",LR_AUTO);

	lr_start_transaction("Pets_SearchWithLastName");

	web_submit_data("owners", 
		"Action=http://pets.shaft.com/owners", 
		"Method=GET", 
		"EncType=", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://pets.shaft.com/owners/find", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=lastName", "Value=arjun8181", ENDITEM, 
		LAST);

	lr_end_transaction("Pets_SearchWithLastName",LR_AUTO);

	return 0;
}