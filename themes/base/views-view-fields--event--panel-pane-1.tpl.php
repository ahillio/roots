<div id="event-info">
<div class="product">
<h2>Dates</h2>
<div class="event-dates"><div class="product-attr-date"><?php print $fields["field_event_date"]->content; ?></div>
<span style="color:grey;"><?php print $fields["field_event_date_1"]->label; ?></span><br />
<?php print $fields["field_event_date_1"]->content; ?></div>
<div id="register">
<div class="product-title" ><h2><?php /* print $fields["title"]->content; */ ?>Register Now</h2></div>
<?php /* if ($fields["field_audience"]->content == "Adults") {
	$path = "sites/roots.firestick13.net/files/registration and waiver form adults.doc";
	} else {
		$path = "";
	}
	print l('Registration form', $path); */
?>
<div id="stepone">	
	Step 1: Pay the deposit or full price.<br />
	<div id="price-info-wrapper" style="float:left;">Price: <?php print $fields["field_cost"]->content; ?> <br />
	Deposit: <?php print $fields["field_deposit"]->content; ?></div>
	<div id="add-to-cart-button" style="float:right;"><?php print $fields["field_price"]->content; ?></div>
<?php /*	<div class="product-price" style="display: none;"><?php print $fields["field_cost"]->value; ?></div><br />
	<select class="product-attr-option">
        <option googlecart-set-product-price="place-holder">Select payment option</option>
	<option googlecart-set-product-price="<?php print $fields["field_cost"]->content; ?>">Full-payment: <?php print $fields["field_cost"]->content; ?></option>
	<option googlecart-set-product-price="<?php print $fields["field_deposit"]->content; ?>">Deposit: <?php print $fields["field_deposit"]->content; ?></option>
	<?php
	$price = preg_replace('/[\$,]/', '', $fields["field_cost"]->content);
	$deposit = preg_replace('/[\$,]/', '', $fields["field_deposit"]->content); 
	$diff_price=$price-$deposit; ?>
	<option googlecart-set-product-price="<?php print "$".$diff_price; ?>">Balance: <?php print "$".$diff_price; ?></option>
	</select>
	<?php print $fields["nothing"]->content; ?> */ ?>
</div><!-- end stepone -->
<div id="steptwo" style="clear:both;">
<p>Step 2: Download this <?php if ($fields["field_audience"]->content == "Adults") {
	$path = "sites/www.rootsvt.com/files/registration and waiver form adults.pdf";
	} else {
		$path = "sites/www.rootsvt.com/files/registration and waiver form minors.pdf";
	}
	print l('Registration form', $path);
?>, fill it out and email it back to us.</p>
<p style="text-align:center;">or</p>
<p>To Register Offline: Download and fill out your registration form and mail it back to us with a deposit check made out to Roots School. Mail to 192 Bear Notch Rd. Bradford VT 05033.</p>
</div><!-- end steptwo -->
</div>	
</div>
</div>
<p><?php print $fields["field_open_or_filled"] ->label; ?>: <?php print $fields["field_open_or_filled"]->content; ?><br />
Ages <?php print $fields["field_event_age"]->content; ?><br />
<?php print $fields["field_daily_duration"]->label; ?>: <?php print $fields["field_daily_duration"]->content; ?><br />Daily courses do not include meals, camping is available upon request.<br />Overnight courses include meals and camping.</p>
<p><span class="prereq-label"><?php print $fields["field_prerequisites"] ->label; ?></span>
<span class="prereq-course"><?php print $fields["field_prerequisites"]->content; ?></span></p> 
<p><span class="prereq-label"><?php print $fields["field_event_required_for"] ->label; ?></span>
<span class="prereq-course"><?php print $fields["field_event_required_for"]->content; ?></span></p>

