$(document).ready(function(){
	window.sr = new ScrollReveal();
	sr.reveal('.modal__trigger');
});

$(function() {

  $(document).on("click", function(e) {
    var $item = $(".rad-dropmenu-item");
    if ($item.hasClass("active")) {
      $item.removeClass("active");
    }
  });

  $(".rad-toggle-btn").on('click', function() {
    $(".rad-sidebar").toggleClass("rad-nav-min");
    $(".rad-body-wrapper").toggleClass("rad-nav-min");
    setTimeout(function() {
      initializeCharts();
    }, 200);
  });

  $(".rad-dropdown >.rad-menu-item").on('click', function(e) {
    e.stopPropagation();
    $(".rad-dropmenu-item").removeClass("active");
    $(this).next(".rad-dropmenu-item").toggleClass("active");
  });

  var colors = [
    '#E94B3B',
    '#39C7AA',
    '#1C7EBB',
    '#F98E33'
  ];

  
});











$(function(){
  var $tab_content = $(".tab_panel .tab_content");
  var $tab_heading = $(".tab_panel .tab_heading");
  var $tab_panel = $(".tab_panel");
  var $arrow_class_up = '<i class="fa fa-angle-up"></i>'; // change your icon class 
  var $arrow_class_down = '<i class="fa fa-angle-down"></i>'; // change your icon class 
  
  $tab_content.hide(); //hide all the .tab_content
  
  $tab_panel.find(".tab_content").eq(0).show();
  $tab_heading.on("click", function(){
    
    $(this).find("span i").html($(this).find("span i").html() ==   $arrow_class_up ? $arrow_class_down : $arrow_class_up);
   
   sr.sync();
    // unhide below code if you want one panel to be always opened
    // $(this).parents(".panel").find(".tab_content").stop().slideUp();
    // $(this).next(".tab_content").stop().slideDown();
      $(this).next(".tab_content").stop().slideToggle();
  });
});