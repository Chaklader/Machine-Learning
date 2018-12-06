


<!DOCTYPE html>
<html>
  <head>
    <meta charset='utf-8'>
    <meta http-equiv="X-UA-Compatible" content="chrome=1">
        <title>AFMotor.h at master from adafruit/Adafruit-Motor-Shield-library - GitHub</title>
    <link rel="search" type="application/opensearchdescription+xml" href="/opensearch.xml" title="GitHub" />
    <link rel="fluid-icon" href="https://github.com/fluidicon.png" title="GitHub" />

    
    

    <meta content="authenticity_token" name="csrf-param" />
<meta content="6OcPYK5JENuW/URzNviLo43RUoZJXXlbKRdV8OYjWOU=" name="csrf-token" />

    <link href="https://a248.e.akamai.net/assets.github.com/stylesheets/bundles/github-1848b742a9acbff1d5d2c6330a8b05b72ee50ae3.css" media="screen" rel="stylesheet" type="text/css" />
    

    <script src="https://a248.e.akamai.net/assets.github.com/javascripts/bundles/jquery-2bc2166e57f5431e5833dd07a7967add26495916.js" type="text/javascript"></script>
    <script src="https://a248.e.akamai.net/assets.github.com/javascripts/bundles/github-3951fffcb751ff2a36fe0e11b83a6de135bce9d9.js" type="text/javascript"></script>
    

      <link rel='permalink' href='/adafruit/Adafruit-Motor-Shield-library/blob/dd30da7ecb40581377dc4bb8fc9044a995ddb4d4/AFMotor.h'>
    

    <meta name="description" content="Adafruit-Motor-Shield-library - Adafruit Motor shield firmware with basic Microstepping support. Works with all Arduinos and the Mega" />
  <link href="https://github.com/adafruit/Adafruit-Motor-Shield-library/commits/master.atom" rel="alternate" title="Recent Commits to Adafruit-Motor-Shield-library:master" type="application/atom+xml" />

  </head>


  <body class="logged_out page-blob windows vis-public env-production ">
    


    

      <div id="header" class="true clearfix">
        <div class="container" class="clearfix">
          <a class="site-logo" href="https://github.com">
            <!--[if IE]>
            <img alt="GitHub" class="github-logo" src="https://a248.e.akamai.net/assets.github.com/images/modules/header/logov7.png?1323882716" />
            <img alt="GitHub" class="github-logo-hover" src="https://a248.e.akamai.net/assets.github.com/images/modules/header/logov7-hover.png?1324325358" />
            <![endif]-->
            <img alt="GitHub" class="github-logo-4x" height="30" src="https://a248.e.akamai.net/assets.github.com/images/modules/header/logov7@4x.png?1323882716" />
            <img alt="GitHub" class="github-logo-4x-hover" height="30" src="https://a248.e.akamai.net/assets.github.com/images/modules/header/logov7@4x-hover.png?1324325358" />
          </a>

                <!--
      make sure to use fully qualified URLs here since this nav
      is used on error pages on other domains
    -->
    <ul class="top-nav logged_out">
        <li class="pricing"><a href="https://github.com/plans">Signup and Pricing</a></li>
        <li class="explore"><a href="https://github.com/explore">Explore GitHub</a></li>
      <li class="features"><a href="https://github.com/features">Features</a></li>
        <li class="blog"><a href="https://github.com/blog">Blog</a></li>
      <li class="login"><a href="https://github.com/login?return_to=%2Fadafruit%2FAdafruit-Motor-Shield-library%2Fblob%2Fmaster%2FAFMotor.h">Login</a></li>
    </ul>


        </div>
      </div>

      

            <div class="site">
      <div class="container">
        <div class="pagehead repohead instapaper_ignore readability-menu">


        <div class="title-actions-bar">
          <h1>
            <a href="/adafruit">adafruit</a> /
            <strong><a href="/adafruit/Adafruit-Motor-Shield-library" class="js-current-repository">Adafruit-Motor-Shield-library</a></strong>
          </h1>
          



              <ul class="pagehead-actions">


          <li><a href="/login?return_to=%2Fadafruit%2FAdafruit-Motor-Shield-library" class="minibutton btn-watch watch-button entice tooltipped leftwards" rel="nofollow" title="You must be logged in to use this feature"><span><span class="icon"></span>Watch</span></a></li>
          <li><a href="/login?return_to=%2Fadafruit%2FAdafruit-Motor-Shield-library" class="minibutton btn-fork fork-button entice tooltipped leftwards" rel="nofollow" title="You must be logged in to use this feature"><span><span class="icon"></span>Fork</span></a></li>


      <li class="repostats">
        <ul class="repo-stats">
          <li class="watchers ">
            <a href="/adafruit/Adafruit-Motor-Shield-library/watchers" title="Watchers" class="tooltipped downwards">
              21
            </a>
          </li>
          <li class="forks">
            <a href="/adafruit/Adafruit-Motor-Shield-library/network" title="Forks" class="tooltipped downwards">
              4
            </a>
          </li>
        </ul>
      </li>
    </ul>

        </div>

          

  <ul class="tabs">
    <li><a href="/adafruit/Adafruit-Motor-Shield-library" class="selected" highlight="repo_sourcerepo_downloadsrepo_commitsrepo_tagsrepo_branches">Code</a></li>
    <li><a href="/adafruit/Adafruit-Motor-Shield-library/network" highlight="repo_networkrepo_fork_queue">Network</a>
    <li><a href="/adafruit/Adafruit-Motor-Shield-library/pulls" highlight="repo_pulls">Pull Requests <span class='counter'>0</span></a></li>

      <li><a href="/adafruit/Adafruit-Motor-Shield-library/issues" highlight="repo_issues">Issues <span class='counter'>2</span></a></li>


    <li><a href="/adafruit/Adafruit-Motor-Shield-library/graphs" highlight="repo_graphsrepo_contributors">Stats &amp; Graphs</a></li>

  </ul>

  
<div class="frame frame-center tree-finder" style="display:none"
      data-tree-list-url="/adafruit/Adafruit-Motor-Shield-library/tree-list/dd30da7ecb40581377dc4bb8fc9044a995ddb4d4"
      data-blob-url-prefix="/adafruit/Adafruit-Motor-Shield-library/blob/dd30da7ecb40581377dc4bb8fc9044a995ddb4d4"
    >

  <div class="breadcrumb">
    <b><a href="/adafruit/Adafruit-Motor-Shield-library">Adafruit-Motor-Shield-library</a></b> /
    <input class="tree-finder-input js-navigation-enable" type="text" name="query" autocomplete="off" spellcheck="false">
  </div>

    <div class="octotip">
      <p>
        <a href="/adafruit/Adafruit-Motor-Shield-library/dismiss-tree-finder-help" class="dismiss js-dismiss-tree-list-help" title="Hide this notice forever" rel="nofollow">Dismiss</a>
        <strong>Octotip:</strong> You've activated the <em>file finder</em>
        by pressing <span class="kbd">t</span> Start typing to filter the
        file list. Use <span class="kbd badmono">↑</span> and
        <span class="kbd badmono">↓</span> to navigate,
        <span class="kbd">enter</span> to view files.
      </p>
    </div>

  <table class="tree-browser" cellpadding="0" cellspacing="0">
    <tr class="js-header"><th>&nbsp;</th><th>name</th></tr>
    <tr class="js-no-results no-results" style="display: none">
      <th colspan="2">No matching files</th>
    </tr>
    <tbody class="js-results-list js-navigation-container" data-navigation-enable-mouse>
    </tbody>
  </table>
</div>

<div id="jump-to-line" style="display:none">
  <h2>Jump to Line</h2>
  <form>
    <input class="textfield" type="text">
    <div class="full-button">
      <button type="submit" class="classy">
        <span>Go</span>
      </button>
    </div>
  </form>
</div>


<div class="subnav-bar">

  <ul class="actions">
    
      <li class="switcher">

        <div class="context-menu-container js-menu-container">
          <span class="text">Current branch:</span>
          <a href="#"
             class="minibutton bigger switcher context-menu-button js-menu-target js-commitish-button btn-branch repo-tree"
             data-master-branch="master"
             data-ref="master">
            <span><span class="icon"></span>master</span>
          </a>

          <div class="context-pane commitish-context js-menu-content">
            <a href="javascript:;" class="close js-menu-close"></a>
            <div class="title">Switch Branches/Tags</div>
            <div class="body pane-selector commitish-selector js-filterable-commitishes">
              <div class="filterbar">
                <div class="placeholder-field js-placeholder-field">
                  <label class="placeholder" for="context-commitish-filter-field" data-placeholder-mode="sticky">Filter branches/tags</label>
                  <input type="text" id="context-commitish-filter-field" class="commitish-filter" />
                </div>

                <ul class="tabs">
                  <li><a href="#" data-filter="branches" class="selected">Branches</a></li>
                  <li><a href="#" data-filter="tags">Tags</a></li>
                </ul>
              </div>

                <div class="commitish-item branch-commitish selector-item">
                  <h4>
                      <a href="/adafruit/Adafruit-Motor-Shield-library/blob/master/AFMotor.h" data-name="master">master</a>
                  </h4>
                </div>


              <div class="no-results" style="display:none">Nothing to show</div>
            </div>
          </div><!-- /.commitish-context-context -->
        </div>

      </li>
  </ul>

  <ul class="subnav">
    <li><a href="/adafruit/Adafruit-Motor-Shield-library" class="selected" highlight="repo_source">Files</a></li>
    <li><a href="/adafruit/Adafruit-Motor-Shield-library/commits/master" highlight="repo_commits">Commits</a></li>
    <li><a href="/adafruit/Adafruit-Motor-Shield-library/branches" class="" highlight="repo_branches">Branches <span class="counter">1</span></a></li>
    <li><a href="/adafruit/Adafruit-Motor-Shield-library/tags" class="blank" highlight="repo_tags">Tags <span class="counter">0</span></a></li>
    <li><a href="/adafruit/Adafruit-Motor-Shield-library/downloads" class="blank" highlight="repo_downloads">Downloads <span class="counter">0</span></a></li>
  </ul>

</div>

  
  
  


          

        </div><!-- /.repohead -->

        




  
  <p class="last-commit">Latest commit to the <strong>master</strong> branch</p>

<div class="commit commit-tease js-details-container">
  <p class="commit-title ">
      <a href="/adafruit/Adafruit-Motor-Shield-library/commit/dd30da7ecb40581377dc4bb8fc9044a995ddb4d4" class="message">Arduino 1.0 compatible</a>
      
  </p>
  <div class="commit-meta">
    <a href="/adafruit/Adafruit-Motor-Shield-library/commit/dd30da7ecb40581377dc4bb8fc9044a995ddb4d4" class="sha-block">commit <span class="sha">dd30da7ecb</span></a>

    <div class="authorship">
      <img class="gravatar" height="20" src="https://secure.gravatar.com/avatar/60abc8771141390d5c286d698b251295?s=140&amp;d=https://a248.e.akamai.net/assets.github.com%2Fimages%2Fgravatars%2Fgravatar-140.png" width="20" />
      <span class="author-name"><a href="/PaintYourDragon">PaintYourDragon</a></span>
      authored <time class="js-relative-date" datetime="2011-12-02T17:37:41-08:00" title="2011-12-02 17:37:41">December 02, 2011</time>

    </div>
  </div>
</div>


  <div id="slider">

    <div class="breadcrumb" data-path="AFMotor.h/">
      <b><a href="/adafruit/Adafruit-Motor-Shield-library/tree/3a4bad11ffe469ead62c48ca080ec7f84db35c6b" class="js-rewrite-sha">Adafruit-Motor-Shield-library</a></b> / AFMotor.h       <span style="display:none" id="clippy_3008" class="clippy-text">AFMotor.h</span>
      
      <object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000"
              width="110"
              height="14"
              class="clippy"
              id="clippy" >
      <param name="movie" value="https://a248.e.akamai.net/assets.github.com/flash/clippy.swf?1315937507?v5"/>
      <param name="allowScriptAccess" value="always" />
      <param name="quality" value="high" />
      <param name="scale" value="noscale" />
      <param NAME="FlashVars" value="id=clippy_3008&amp;copied=copied!&amp;copyto=copy to clipboard">
      <param name="bgcolor" value="#FFFFFF">
      <param name="wmode" value="opaque">
      <embed src="https://a248.e.akamai.net/assets.github.com/flash/clippy.swf?1315937507?v5"
             width="110"
             height="14"
             name="clippy"
             quality="high"
             allowScriptAccess="always"
             type="application/x-shockwave-flash"
             pluginspage="http://www.macromedia.com/go/getflashplayer"
             FlashVars="id=clippy_3008&amp;copied=copied!&amp;copyto=copy to clipboard"
             bgcolor="#FFFFFF"
             wmode="opaque"
      />
      </object>
      

    </div>

    <div class="frames">
      <div class="frame frame-center" data-path="AFMotor.h/" data-permalink-url="/adafruit/Adafruit-Motor-Shield-library/blob/3a4bad11ffe469ead62c48ca080ec7f84db35c6b/AFMotor.h" data-title="AFMotor.h at master from adafruit/Adafruit-Motor-Shield-library - GitHub" data-type="blob">
          <ul class="big-actions">
            <li><a class="file-edit-link minibutton js-rewrite-sha" href="/adafruit/Adafruit-Motor-Shield-library/edit/3a4bad11ffe469ead62c48ca080ec7f84db35c6b/AFMotor.h" data-method="post"><span>Edit this file</span></a></li>
          </ul>

        <div id="files">
          <div class="file">
            <div class="meta">
              <div class="info">
                <span class="icon"><img alt="Txt" height="16" src="https://a248.e.akamai.net/assets.github.com/images/icons/txt.png?1315937507" width="16" /></span>
                <span class="mode" title="File Mode">100644</span>
                  <span>105 lines (83 sloc)</span>
                <span>2.023 kb</span>
              </div>
              <ul class="actions">
                <li><a href="/adafruit/Adafruit-Motor-Shield-library/raw/master/AFMotor.h" id="raw-url">raw</a></li>
                  <li><a href="/adafruit/Adafruit-Motor-Shield-library/blame/master/AFMotor.h">blame</a></li>
                <li><a href="/adafruit/Adafruit-Motor-Shield-library/commits/master/AFMotor.h" rel="nofollow">history</a></li>
              </ul>
            </div>
              <div class="data type-c">
      <table cellpadding="0" cellspacing="0" class="lines">
        <tr>
          <td>
            <pre class="line_numbers"><span id="L1" rel="#L1">1</span>
<span id="L2" rel="#L2">2</span>
<span id="L3" rel="#L3">3</span>
<span id="L4" rel="#L4">4</span>
<span id="L5" rel="#L5">5</span>
<span id="L6" rel="#L6">6</span>
<span id="L7" rel="#L7">7</span>
<span id="L8" rel="#L8">8</span>
<span id="L9" rel="#L9">9</span>
<span id="L10" rel="#L10">10</span>
<span id="L11" rel="#L11">11</span>
<span id="L12" rel="#L12">12</span>
<span id="L13" rel="#L13">13</span>
<span id="L14" rel="#L14">14</span>
<span id="L15" rel="#L15">15</span>
<span id="L16" rel="#L16">16</span>
<span id="L17" rel="#L17">17</span>
<span id="L18" rel="#L18">18</span>
<span id="L19" rel="#L19">19</span>
<span id="L20" rel="#L20">20</span>
<span id="L21" rel="#L21">21</span>
<span id="L22" rel="#L22">22</span>
<span id="L23" rel="#L23">23</span>
<span id="L24" rel="#L24">24</span>
<span id="L25" rel="#L25">25</span>
<span id="L26" rel="#L26">26</span>
<span id="L27" rel="#L27">27</span>
<span id="L28" rel="#L28">28</span>
<span id="L29" rel="#L29">29</span>
<span id="L30" rel="#L30">30</span>
<span id="L31" rel="#L31">31</span>
<span id="L32" rel="#L32">32</span>
<span id="L33" rel="#L33">33</span>
<span id="L34" rel="#L34">34</span>
<span id="L35" rel="#L35">35</span>
<span id="L36" rel="#L36">36</span>
<span id="L37" rel="#L37">37</span>
<span id="L38" rel="#L38">38</span>
<span id="L39" rel="#L39">39</span>
<span id="L40" rel="#L40">40</span>
<span id="L41" rel="#L41">41</span>
<span id="L42" rel="#L42">42</span>
<span id="L43" rel="#L43">43</span>
<span id="L44" rel="#L44">44</span>
<span id="L45" rel="#L45">45</span>
<span id="L46" rel="#L46">46</span>
<span id="L47" rel="#L47">47</span>
<span id="L48" rel="#L48">48</span>
<span id="L49" rel="#L49">49</span>
<span id="L50" rel="#L50">50</span>
<span id="L51" rel="#L51">51</span>
<span id="L52" rel="#L52">52</span>
<span id="L53" rel="#L53">53</span>
<span id="L54" rel="#L54">54</span>
<span id="L55" rel="#L55">55</span>
<span id="L56" rel="#L56">56</span>
<span id="L57" rel="#L57">57</span>
<span id="L58" rel="#L58">58</span>
<span id="L59" rel="#L59">59</span>
<span id="L60" rel="#L60">60</span>
<span id="L61" rel="#L61">61</span>
<span id="L62" rel="#L62">62</span>
<span id="L63" rel="#L63">63</span>
<span id="L64" rel="#L64">64</span>
<span id="L65" rel="#L65">65</span>
<span id="L66" rel="#L66">66</span>
<span id="L67" rel="#L67">67</span>
<span id="L68" rel="#L68">68</span>
<span id="L69" rel="#L69">69</span>
<span id="L70" rel="#L70">70</span>
<span id="L71" rel="#L71">71</span>
<span id="L72" rel="#L72">72</span>
<span id="L73" rel="#L73">73</span>
<span id="L74" rel="#L74">74</span>
<span id="L75" rel="#L75">75</span>
<span id="L76" rel="#L76">76</span>
<span id="L77" rel="#L77">77</span>
<span id="L78" rel="#L78">78</span>
<span id="L79" rel="#L79">79</span>
<span id="L80" rel="#L80">80</span>
<span id="L81" rel="#L81">81</span>
<span id="L82" rel="#L82">82</span>
<span id="L83" rel="#L83">83</span>
<span id="L84" rel="#L84">84</span>
<span id="L85" rel="#L85">85</span>
<span id="L86" rel="#L86">86</span>
<span id="L87" rel="#L87">87</span>
<span id="L88" rel="#L88">88</span>
<span id="L89" rel="#L89">89</span>
<span id="L90" rel="#L90">90</span>
<span id="L91" rel="#L91">91</span>
<span id="L92" rel="#L92">92</span>
<span id="L93" rel="#L93">93</span>
<span id="L94" rel="#L94">94</span>
<span id="L95" rel="#L95">95</span>
<span id="L96" rel="#L96">96</span>
<span id="L97" rel="#L97">97</span>
<span id="L98" rel="#L98">98</span>
<span id="L99" rel="#L99">99</span>
<span id="L100" rel="#L100">100</span>
<span id="L101" rel="#L101">101</span>
<span id="L102" rel="#L102">102</span>
<span id="L103" rel="#L103">103</span>
<span id="L104" rel="#L104">104</span>
<span id="L105" rel="#L105">105</span>
</pre>
          </td>
          <td width="100%">
                <div class="highlight"><pre><div class='line' id='LC1'><span class="cp">// Adafruit Motor shield library</span></div><div class='line' id='LC2'><span class="cp">// copyright Adafruit Industries LLC, 2009</span></div><div class='line' id='LC3'><span class="cp">// this code is public domain, enjoy!</span></div><div class='line' id='LC4'><br/></div><div class='line' id='LC5'><span class="cp">#ifndef _AFMotor_h_</span></div><div class='line' id='LC6'><span class="cp">#define _AFMotor_h_</span></div><div class='line' id='LC7'><br/></div><div class='line' id='LC8'><span class="cp">#include &lt;inttypes.h&gt;</span></div><div class='line' id='LC9'><span class="cp">#include &lt;avr/io.h&gt;</span></div><div class='line' id='LC10'><br/></div><div class='line' id='LC11'><span class="cp">//#define MOTORDEBUG 1</span></div><div class='line' id='LC12'><br/></div><div class='line' id='LC13'><span class="cp">#define MICROSTEPS 16         </span><span class="c1">// 8 or 16</span></div><div class='line' id='LC14'><br/></div><div class='line' id='LC15'><span class="cp">#define MOTOR12_64KHZ _BV(CS20)  </span><span class="c1">// no prescale</span></div><div class='line' id='LC16'><span class="cp">#define MOTOR12_8KHZ _BV(CS21)   </span><span class="c1">// divide by 8</span></div><div class='line' id='LC17'><span class="cp">#define MOTOR12_2KHZ _BV(CS21) | _BV(CS20) </span><span class="c1">// divide by 32</span></div><div class='line' id='LC18'><span class="cp">#define MOTOR12_1KHZ _BV(CS22)  </span><span class="c1">// divide by 64</span></div><div class='line' id='LC19'><br/></div><div class='line' id='LC20'><span class="cp">#define MOTOR34_64KHZ _BV(CS00)  </span><span class="c1">// no prescale</span></div><div class='line' id='LC21'><span class="cp">#define MOTOR34_8KHZ _BV(CS01)   </span><span class="c1">// divide by 8</span></div><div class='line' id='LC22'><span class="cp">#define MOTOR34_1KHZ _BV(CS01) | _BV(CS00)  </span><span class="c1">// divide by 64</span></div><div class='line' id='LC23'><br/></div><div class='line' id='LC24'><span class="cp">#define MOTOR1_A 2</span></div><div class='line' id='LC25'><span class="cp">#define MOTOR1_B 3</span></div><div class='line' id='LC26'><span class="cp">#define MOTOR2_A 1</span></div><div class='line' id='LC27'><span class="cp">#define MOTOR2_B 4</span></div><div class='line' id='LC28'><span class="cp">#define MOTOR4_A 0</span></div><div class='line' id='LC29'><span class="cp">#define MOTOR4_B 6</span></div><div class='line' id='LC30'><span class="cp">#define MOTOR3_A 5</span></div><div class='line' id='LC31'><span class="cp">#define MOTOR3_B 7</span></div><div class='line' id='LC32'><br/></div><div class='line' id='LC33'><span class="cp">#define FORWARD 1</span></div><div class='line' id='LC34'><span class="cp">#define BACKWARD 2</span></div><div class='line' id='LC35'><span class="cp">#define BRAKE 3</span></div><div class='line' id='LC36'><span class="cp">#define RELEASE 4</span></div><div class='line' id='LC37'><br/></div><div class='line' id='LC38'><span class="cp">#define SINGLE 1</span></div><div class='line' id='LC39'><span class="cp">#define DOUBLE 2</span></div><div class='line' id='LC40'><span class="cp">#define INTERLEAVE 3</span></div><div class='line' id='LC41'><span class="cp">#define MICROSTEP 4</span></div><div class='line' id='LC42'><br/></div><div class='line' id='LC43'><span class="cm">/*</span></div><div class='line' id='LC44'><span class="cm">#define LATCH 4</span></div><div class='line' id='LC45'><span class="cm">#define LATCH_DDR DDRB</span></div><div class='line' id='LC46'><span class="cm">#define LATCH_PORT PORTB</span></div><div class='line' id='LC47'><br/></div><div class='line' id='LC48'><span class="cm">#define CLK_PORT PORTD</span></div><div class='line' id='LC49'><span class="cm">#define CLK_DDR DDRD</span></div><div class='line' id='LC50'><span class="cm">#define CLK 4</span></div><div class='line' id='LC51'><br/></div><div class='line' id='LC52'><span class="cm">#define ENABLE_PORT PORTD</span></div><div class='line' id='LC53'><span class="cm">#define ENABLE_DDR DDRD</span></div><div class='line' id='LC54'><span class="cm">#define ENABLE 7</span></div><div class='line' id='LC55'><br/></div><div class='line' id='LC56'><span class="cm">#define SER 0</span></div><div class='line' id='LC57'><span class="cm">#define SER_DDR DDRB</span></div><div class='line' id='LC58'><span class="cm">#define SER_PORT PORTB</span></div><div class='line' id='LC59'><span class="cm">*/</span></div><div class='line' id='LC60'><br/></div><div class='line' id='LC61'><span class="cp">// Arduino pin names</span></div><div class='line' id='LC62'><span class="cp">#define MOTORLATCH 12</span></div><div class='line' id='LC63'><span class="cp">#define MOTORCLK 4</span></div><div class='line' id='LC64'><span class="cp">#define MOTORENABLE 7</span></div><div class='line' id='LC65'><span class="cp">#define MOTORDATA 8</span></div><div class='line' id='LC66'><br/></div><div class='line' id='LC67'><span class="k">class</span> <span class="nc">AFMotorController</span></div><div class='line' id='LC68'><span class="p">{</span></div><div class='line' id='LC69'>&nbsp;&nbsp;<span class="k">public</span><span class="o">:</span></div><div class='line' id='LC70'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">AFMotorController</span><span class="p">(</span><span class="kt">void</span><span class="p">);</span></div><div class='line' id='LC71'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">void</span> <span class="n">enable</span><span class="p">(</span><span class="kt">void</span><span class="p">);</span></div><div class='line' id='LC72'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">friend</span> <span class="k">class</span> <span class="nc">AF_DCMotor</span><span class="p">;</span></div><div class='line' id='LC73'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">void</span> <span class="n">latch_tx</span><span class="p">(</span><span class="kt">void</span><span class="p">);</span></div><div class='line' id='LC74'><span class="p">};</span></div><div class='line' id='LC75'><br/></div><div class='line' id='LC76'><span class="k">class</span> <span class="nc">AF_DCMotor</span></div><div class='line' id='LC77'><span class="p">{</span></div><div class='line' id='LC78'>&nbsp;<span class="k">public</span><span class="o">:</span></div><div class='line' id='LC79'>&nbsp;&nbsp;<span class="n">AF_DCMotor</span><span class="p">(</span><span class="n">uint8_t</span> <span class="n">motornum</span><span class="p">,</span> <span class="n">uint8_t</span> <span class="n">freq</span> <span class="o">=</span>  <span class="n">MOTOR34_8KHZ</span><span class="p">);</span></div><div class='line' id='LC80'>&nbsp;&nbsp;<span class="kt">void</span> <span class="n">run</span><span class="p">(</span><span class="n">uint8_t</span><span class="p">);</span></div><div class='line' id='LC81'>&nbsp;&nbsp;<span class="kt">void</span> <span class="n">setSpeed</span><span class="p">(</span><span class="n">uint8_t</span><span class="p">);</span></div><div class='line' id='LC82'><br/></div><div class='line' id='LC83'>&nbsp;<span class="k">private</span><span class="o">:</span></div><div class='line' id='LC84'>&nbsp;&nbsp;<span class="n">uint8_t</span> <span class="n">motornum</span><span class="p">,</span> <span class="n">pwmfreq</span><span class="p">;</span></div><div class='line' id='LC85'><span class="p">};</span></div><div class='line' id='LC86'><br/></div><div class='line' id='LC87'><span class="k">class</span> <span class="nc">AF_Stepper</span> <span class="p">{</span></div><div class='line' id='LC88'>&nbsp;<span class="k">public</span><span class="o">:</span></div><div class='line' id='LC89'>&nbsp;&nbsp;<span class="n">AF_Stepper</span><span class="p">(</span><span class="n">uint16_t</span><span class="p">,</span> <span class="n">uint8_t</span><span class="p">);</span></div><div class='line' id='LC90'>&nbsp;&nbsp;<span class="kt">void</span> <span class="n">step</span><span class="p">(</span><span class="n">uint16_t</span> <span class="n">steps</span><span class="p">,</span> <span class="n">uint8_t</span> <span class="n">dir</span><span class="p">,</span>  <span class="n">uint8_t</span> <span class="n">style</span> <span class="o">=</span> <span class="n">SINGLE</span><span class="p">);</span></div><div class='line' id='LC91'>&nbsp;&nbsp;<span class="kt">void</span> <span class="n">setSpeed</span><span class="p">(</span><span class="n">uint16_t</span><span class="p">);</span></div><div class='line' id='LC92'>&nbsp;&nbsp;<span class="n">uint8_t</span> <span class="n">onestep</span><span class="p">(</span><span class="n">uint8_t</span> <span class="n">dir</span><span class="p">,</span> <span class="n">uint8_t</span> <span class="n">style</span><span class="p">);</span></div><div class='line' id='LC93'>&nbsp;&nbsp;<span class="kt">void</span> <span class="n">release</span><span class="p">(</span><span class="kt">void</span><span class="p">);</span></div><div class='line' id='LC94'>&nbsp;&nbsp;<span class="n">uint16_t</span> <span class="n">revsteps</span><span class="p">;</span> <span class="c1">// # steps per revolution</span></div><div class='line' id='LC95'>&nbsp;&nbsp;<span class="n">uint8_t</span> <span class="n">steppernum</span><span class="p">;</span></div><div class='line' id='LC96'>&nbsp;&nbsp;<span class="n">uint32_t</span> <span class="n">usperstep</span><span class="p">,</span> <span class="n">steppingcounter</span><span class="p">;</span></div><div class='line' id='LC97'>&nbsp;<span class="k">private</span><span class="o">:</span></div><div class='line' id='LC98'>&nbsp;&nbsp;<span class="n">uint8_t</span> <span class="n">currentstep</span><span class="p">;</span></div><div class='line' id='LC99'><br/></div><div class='line' id='LC100'><span class="p">};</span></div><div class='line' id='LC101'><br/></div><div class='line' id='LC102'><span class="n">uint8_t</span> <span class="n">getlatchstate</span><span class="p">(</span><span class="kt">void</span><span class="p">);</span></div><div class='line' id='LC103'><br/></div><div class='line' id='LC104'><span class="cp">#endif</span></div><div class='line' id='LC105'><br/></div></pre></div>
          </td>
        </tr>
      </table>
  </div>

          </div>
        </div>
      </div>
    </div>

  </div>

<div class="frame frame-loading" style="display:none;" data-tree-list-url="/adafruit/Adafruit-Motor-Shield-library/tree-list/dd30da7ecb40581377dc4bb8fc9044a995ddb4d4" data-blob-url-prefix="/adafruit/Adafruit-Motor-Shield-library/blob/dd30da7ecb40581377dc4bb8fc9044a995ddb4d4">
  <img src="https://a248.e.akamai.net/assets.github.com/images/modules/ajax/big_spinner_336699.gif?1315867479" height="32" width="32">
</div>

      </div>
    </div>

    <!-- footer -->
    <div id="footer" >
      
  <div class="upper_footer">
     <div class="container" class="clearfix">

       <!--[if IE]><h4 id="blacktocat_ie">GitHub Links</h4><![endif]-->
       <![if !IE]><h4 id="blacktocat">GitHub Links</h4><![endif]>

       <ul class="footer_nav">
         <h4>GitHub</h4>
         <li><a href="https://github.com/about">About</a></li>
         <li><a href="https://github.com/blog">Blog</a></li>
         <li><a href="https://github.com/features">Features</a></li>
         <li><a href="https://github.com/contact">Contact &amp; Support</a></li>
         <li><a href="https://github.com/training">Training</a></li>
         <li><a href="http://enterprise.github.com/">GitHub Enterprise</a></li>
         <li><a href="http://status.github.com/">Site Status</a></li>
       </ul>

       <ul class="footer_nav">
         <h4>Tools</h4>
         <li><a href="http://get.gaug.es/">Gauges: Analyze web traffic</a></li>
         <li><a href="http://speakerdeck.com">Speakerdeck: Presentations</a></li>
         <li><a href="https://gist.github.com">Gist: Code snippets</a></li>
         <li><a href="http://mac.github.com/">GitHub for Mac</a></li>
         <li><a href="http://mobile.github.com/">Issues for iPhone</a></li>
         <li><a href="http://jobs.github.com/">Job Board</a></li>
       </ul>

       <ul class="footer_nav">
         <h4>Extras</h4>
         <li><a href="http://shop.github.com/">GitHub Shop</a></li>
         <li><a href="http://octodex.github.com/">The Octodex</a></li>
       </ul>

       <ul class="footer_nav">
         <h4>Documentation</h4>
         <li><a href="http://help.github.com/">GitHub Help</a></li>
         <li><a href="http://developer.github.com/">Developer API</a></li>
         <li><a href="http://github.github.com/github-flavored-markdown/">GitHub Flavored Markdown</a></li>
         <li><a href="http://pages.github.com/">GitHub Pages</a></li>
       </ul>

     </div><!-- /.site -->
  </div><!-- /.upper_footer -->

<div class="lower_footer">
  <div class="container" class="clearfix">
    <!--[if IE]><div id="legal_ie"><![endif]-->
    <![if !IE]><div id="legal"><![endif]>
      <ul>
          <li><a href="https://github.com/site/terms">Terms of Service</a></li>
          <li><a href="https://github.com/site/privacy">Privacy</a></li>
          <li><a href="https://github.com/security">Security</a></li>
      </ul>

      <p>&copy; 2011 <span id="_rrt" title="0.06625s from fe9.rs.github.com">GitHub</span> Inc. All rights reserved.</p>
    </div><!-- /#legal or /#legal_ie-->

      <div class="sponsor">
        <a href="http://www.rackspace.com" class="logo">
          <img alt="Dedicated Server" height="36" src="https://a248.e.akamai.net/assets.github.com/images/modules/footer/rackspace_logo.png?v2" width="38" />
        </a>
        Powered by the <a href="http://www.rackspace.com ">Dedicated
        Servers</a> and<br/> <a href="http://www.rackspacecloud.com">Cloud
        Computing</a> of Rackspace Hosting<span>&reg;</span>
      </div>
  </div><!-- /.site -->
</div><!-- /.lower_footer -->

    </div><!-- /#footer -->

    

<div id="keyboard_shortcuts_pane" class="instapaper_ignore readability-extra" style="display:none">
  <h2>Keyboard Shortcuts <small><a href="#" class="js-see-all-keyboard-shortcuts">(see all)</a></small></h2>

  <div class="columns threecols">
    <div class="column first">
      <h3>Site wide shortcuts</h3>
      <dl class="keyboard-mappings">
        <dt>s</dt>
        <dd>Focus site search</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>?</dt>
        <dd>Bring up this help dialog</dd>
      </dl>
    </div><!-- /.column.first -->

    <div class="column middle" style='display:none'>
      <h3>Commit list</h3>
      <dl class="keyboard-mappings">
        <dt>j</dt>
        <dd>Move selection down</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>k</dt>
        <dd>Move selection up</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>c <em>or</em> o <em>or</em> enter</dt>
        <dd>Open commit</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>y</dt>
        <dd>Expand URL to its canonical form</dd>
      </dl>
    </div><!-- /.column.first -->

    <div class="column last" style='display:none'>
      <h3>Pull request list</h3>
      <dl class="keyboard-mappings">
        <dt>j</dt>
        <dd>Move selection down</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>k</dt>
        <dd>Move selection up</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>o <em>or</em> enter</dt>
        <dd>Open issue</dd>
      </dl>
    </div><!-- /.columns.last -->

  </div><!-- /.columns.equacols -->

  <div style='display:none'>
    <div class="rule"></div>

    <h3>Issues</h3>

    <div class="columns threecols">
      <div class="column first">
        <dl class="keyboard-mappings">
          <dt>j</dt>
          <dd>Move selection down</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>k</dt>
          <dd>Move selection up</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>x</dt>
          <dd>Toggle selection</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>o <em>or</em> enter</dt>
          <dd>Open issue</dd>
        </dl>
      </div><!-- /.column.first -->
      <div class="column middle">
        <dl class="keyboard-mappings">
          <dt>I</dt>
          <dd>Mark selection as read</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>U</dt>
          <dd>Mark selection as unread</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>e</dt>
          <dd>Close selection</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>y</dt>
          <dd>Remove selection from view</dd>
        </dl>
      </div><!-- /.column.middle -->
      <div class="column last">
        <dl class="keyboard-mappings">
          <dt>c</dt>
          <dd>Create issue</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>l</dt>
          <dd>Create label</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>i</dt>
          <dd>Back to inbox</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>u</dt>
          <dd>Back to issues</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>/</dt>
          <dd>Focus issues search</dd>
        </dl>
      </div>
    </div>
  </div>

  <div style='display:none'>
    <div class="rule"></div>

    <h3>Issues Dashboard</h3>

    <div class="columns threecols">
      <div class="column first">
        <dl class="keyboard-mappings">
          <dt>j</dt>
          <dd>Move selection down</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>k</dt>
          <dd>Move selection up</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>o <em>or</em> enter</dt>
          <dd>Open issue</dd>
        </dl>
      </div><!-- /.column.first -->
    </div>
  </div>

  <div style='display:none'>
    <div class="rule"></div>

    <h3>Network Graph</h3>
    <div class="columns equacols">
      <div class="column first">
        <dl class="keyboard-mappings">
          <dt><span class="badmono">←</span> <em>or</em> h</dt>
          <dd>Scroll left</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt><span class="badmono">→</span> <em>or</em> l</dt>
          <dd>Scroll right</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt><span class="badmono">↑</span> <em>or</em> k</dt>
          <dd>Scroll up</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt><span class="badmono">↓</span> <em>or</em> j</dt>
          <dd>Scroll down</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>t</dt>
          <dd>Toggle visibility of head labels</dd>
        </dl>
      </div><!-- /.column.first -->
      <div class="column last">
        <dl class="keyboard-mappings">
          <dt>shift <span class="badmono">←</span> <em>or</em> shift h</dt>
          <dd>Scroll all the way left</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>shift <span class="badmono">→</span> <em>or</em> shift l</dt>
          <dd>Scroll all the way right</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>shift <span class="badmono">↑</span> <em>or</em> shift k</dt>
          <dd>Scroll all the way up</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>shift <span class="badmono">↓</span> <em>or</em> shift j</dt>
          <dd>Scroll all the way down</dd>
        </dl>
      </div><!-- /.column.last -->
    </div>
  </div>

  <div >
    <div class="rule"></div>
    <div class="columns threecols">
      <div class="column first" >
        <h3>Source Code Browsing</h3>
        <dl class="keyboard-mappings">
          <dt>t</dt>
          <dd>Activates the file finder</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>l</dt>
          <dd>Jump to line</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>w</dt>
          <dd>Switch branch/tag</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>y</dt>
          <dd>Expand URL to its canonical form</dd>
        </dl>
      </div>
    </div>
  </div>
</div>

    <div id="markdown-help" class="instapaper_ignore readability-extra">
  <h2>Markdown Cheat Sheet</h2>

  <div class="cheatsheet-content">

  <div class="mod">
    <div class="col">
      <h3>Format Text</h3>
      <p>Headers</p>
      <pre>
# This is an &lt;h1&gt; tag
## This is an &lt;h2&gt; tag
###### This is an &lt;h6&gt; tag</pre>
     <p>Text styles</p>
     <pre>
*This text will be italic*
_This will also be italic_
**This text will be bold**
__This will also be bold__

*You **can** combine them*
</pre>
    </div>
    <div class="col">
      <h3>Lists</h3>
      <p>Unordered</p>
      <pre>
* Item 1
* Item 2
  * Item 2a
  * Item 2b</pre>
     <p>Ordered</p>
     <pre>
1. Item 1
2. Item 2
3. Item 3
   * Item 3a
   * Item 3b</pre>
    </div>
    <div class="col">
      <h3>Miscellaneous</h3>
      <p>Images</p>
      <pre>
![GitHub Logo](/images/logo.png)
Format: ![Alt Text](url)
</pre>
     <p>Links</p>
     <pre>
http://github.com - automatic!
[GitHub](http://github.com)</pre>
<p>Blockquotes</p>
     <pre>
As Kanye West said:

> We're living the future so
> the present is our past.
</pre>
    </div>
  </div>
  <div class="rule"></div>

  <h3>Code Examples in Markdown</h3>
  <div class="col">
      <p>Syntax highlighting with <a href="http://github.github.com/github-flavored-markdown/" title="GitHub Flavored Markdown" target="_blank">GFM</a></p>
      <pre>
```javascript
function fancyAlert(arg) {
  if(arg) {
    $.facebox({div:'#foo'})
  }
}
```</pre>
    </div>
    <div class="col">
      <p>Or, indent your code 4 spaces</p>
      <pre>
Here is a Python code example
without syntax highlighting:

    def foo:
      if not bar:
        return true</pre>
    </div>
    <div class="col">
      <p>Inline code for comments</p>
      <pre>
I think you should use an
`&lt;addr&gt;` element here instead.</pre>
    </div>
  </div>

  </div>
</div>


    <div class="context-overlay"></div>

    <div class="ajax-error-message">
      <p><span class="icon"></span> Something went wrong with that request. Please try again. <a href="javascript:;" class="ajax-error-dismiss">Dismiss</a></p>
    </div>

    
    
    
  </body>
</html>

