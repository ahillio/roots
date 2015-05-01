<?php /* dpm($fields); */ ?>

<div id="event-info">
<span id="tosignup">To sign up for</span>
<div class="product-title"><?php print $fields["title"]->content; ?></div>
<span id="signup-instruct">Click the blue button to pay the deposit, then fill registration form and send it to us.</span>
<?php print $fields["field_open_or_filled"]->content; ?>
<?php print $fields["field_event_age"]->content; ?>
<div id="datepricebuy">
	<?php print $fields["field_event_date"]->content; ?>
	Price: <?php print $fields["field_cost"]->content; ?>
	Deposit: <div class="product-price"><?php print $fields["field_deposit"]->content; ?></div>
	<?php print $fields["nothing"]->content; ?>
	<script id="googlecart-script" type="text/javascript" src="http://checkout.google.com/seller/gsc/v2/cart.js?mid=348839614416051" currency="USD" <?php /* post-cart-to-sandbox="true" */ ?> > </script>
</div> <!-- end datepricebuy -->
<?php print $fields["field_event_file"]->content; ?>
To enroll in this course you must have previously taken the course: <?php print $fields["field_prerequisites"]->content; ?>
This course is required for enrollment in the course: <?php print $fields["field_event_required_for"]->content; ?>
</div>
