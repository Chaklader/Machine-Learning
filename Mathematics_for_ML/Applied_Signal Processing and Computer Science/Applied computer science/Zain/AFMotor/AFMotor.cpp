


<!DOCTYPE html>
<html>
  <head>
    <meta charset='utf-8'>
    <meta http-equiv="X-UA-Compatible" content="chrome=1">
        <title>AFMotor.cpp at master from adafruit/Adafruit-Motor-Shield-library - GitHub</title>
    <link rel="search" type="application/opensearchdescription+xml" href="/opensearch.xml" title="GitHub" />
    <link rel="fluid-icon" href="https://github.com/fluidicon.png" title="GitHub" />

    
    

    <meta content="authenticity_token" name="csrf-param" />
<meta content="6OcPYK5JENuW/URzNviLo43RUoZJXXlbKRdV8OYjWOU=" name="csrf-token" />

    <link href="https://a248.e.akamai.net/assets.github.com/stylesheets/bundles/github-1848b742a9acbff1d5d2c6330a8b05b72ee50ae3.css" media="screen" rel="stylesheet" type="text/css" />
    

    <script src="https://a248.e.akamai.net/assets.github.com/javascripts/bundles/jquery-2bc2166e57f5431e5833dd07a7967add26495916.js" type="text/javascript"></script>
    <script src="https://a248.e.akamai.net/assets.github.com/javascripts/bundles/github-3951fffcb751ff2a36fe0e11b83a6de135bce9d9.js" type="text/javascript"></script>
    

      <link rel='permalink' href='/adafruit/Adafruit-Motor-Shield-library/blob/dd30da7ecb40581377dc4bb8fc9044a995ddb4d4/AFMotor.cpp'>
    

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
      <li class="login"><a href="https://github.com/login?return_to=%2Fadafruit%2FAdafruit-Motor-Shield-library%2Fblob%2Fmaster%2FAFMotor.cpp">Login</a></li>
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
                      <a href="/adafruit/Adafruit-Motor-Shield-library/blob/master/AFMotor.cpp" data-name="master">master</a>
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

    <div class="breadcrumb" data-path="AFMotor.cpp/">
      <b><a href="/adafruit/Adafruit-Motor-Shield-library/tree/dd30da7ecb40581377dc4bb8fc9044a995ddb4d4" class="js-rewrite-sha">Adafruit-Motor-Shield-library</a></b> / AFMotor.cpp       <span style="display:none" id="clippy_327" class="clippy-text">AFMotor.cpp</span>
      
      <object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000"
              width="110"
              height="14"
              class="clippy"
              id="clippy" >
      <param name="movie" value="https://a248.e.akamai.net/assets.github.com/flash/clippy.swf?1315937721?v5"/>
      <param name="allowScriptAccess" value="always" />
      <param name="quality" value="high" />
      <param name="scale" value="noscale" />
      <param NAME="FlashVars" value="id=clippy_327&amp;copied=copied!&amp;copyto=copy to clipboard">
      <param name="bgcolor" value="#FFFFFF">
      <param name="wmode" value="opaque">
      <embed src="https://a248.e.akamai.net/assets.github.com/flash/clippy.swf?1315937721?v5"
             width="110"
             height="14"
             name="clippy"
             quality="high"
             allowScriptAccess="always"
             type="application/x-shockwave-flash"
             pluginspage="http://www.macromedia.com/go/getflashplayer"
             FlashVars="id=clippy_327&amp;copied=copied!&amp;copyto=copy to clipboard"
             bgcolor="#FFFFFF"
             wmode="opaque"
      />
      </object>
      

    </div>

    <div class="frames">
      <div class="frame frame-center" data-path="AFMotor.cpp/" data-permalink-url="/adafruit/Adafruit-Motor-Shield-library/blob/dd30da7ecb40581377dc4bb8fc9044a995ddb4d4/AFMotor.cpp" data-title="AFMotor.cpp at master from adafruit/Adafruit-Motor-Shield-library - GitHub" data-type="blob">
          <ul class="big-actions">
            <li><a class="file-edit-link minibutton js-rewrite-sha" href="/adafruit/Adafruit-Motor-Shield-library/edit/dd30da7ecb40581377dc4bb8fc9044a995ddb4d4/AFMotor.cpp" data-method="post" rel="nofollow"><span>Edit this file</span></a></li>
          </ul>

        <div id="files">
          <div class="file">
            <div class="meta">
              <div class="info">
                <span class="icon"><img alt="Txt" height="16" src="https://a248.e.akamai.net/assets.github.com/images/icons/txt.png?1315937721" width="16" /></span>
                <span class="mode" title="File Mode">100644</span>
                  <span>565 lines (498 sloc)</span>
                <span>14.356 kb</span>
              </div>
              <ul class="actions">
                <li><a href="/adafruit/Adafruit-Motor-Shield-library/raw/master/AFMotor.cpp" id="raw-url">raw</a></li>
                  <li><a href="/adafruit/Adafruit-Motor-Shield-library/blame/master/AFMotor.cpp">blame</a></li>
                <li><a href="/adafruit/Adafruit-Motor-Shield-library/commits/master/AFMotor.cpp" rel="nofollow">history</a></li>
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
<span id="L106" rel="#L106">106</span>
<span id="L107" rel="#L107">107</span>
<span id="L108" rel="#L108">108</span>
<span id="L109" rel="#L109">109</span>
<span id="L110" rel="#L110">110</span>
<span id="L111" rel="#L111">111</span>
<span id="L112" rel="#L112">112</span>
<span id="L113" rel="#L113">113</span>
<span id="L114" rel="#L114">114</span>
<span id="L115" rel="#L115">115</span>
<span id="L116" rel="#L116">116</span>
<span id="L117" rel="#L117">117</span>
<span id="L118" rel="#L118">118</span>
<span id="L119" rel="#L119">119</span>
<span id="L120" rel="#L120">120</span>
<span id="L121" rel="#L121">121</span>
<span id="L122" rel="#L122">122</span>
<span id="L123" rel="#L123">123</span>
<span id="L124" rel="#L124">124</span>
<span id="L125" rel="#L125">125</span>
<span id="L126" rel="#L126">126</span>
<span id="L127" rel="#L127">127</span>
<span id="L128" rel="#L128">128</span>
<span id="L129" rel="#L129">129</span>
<span id="L130" rel="#L130">130</span>
<span id="L131" rel="#L131">131</span>
<span id="L132" rel="#L132">132</span>
<span id="L133" rel="#L133">133</span>
<span id="L134" rel="#L134">134</span>
<span id="L135" rel="#L135">135</span>
<span id="L136" rel="#L136">136</span>
<span id="L137" rel="#L137">137</span>
<span id="L138" rel="#L138">138</span>
<span id="L139" rel="#L139">139</span>
<span id="L140" rel="#L140">140</span>
<span id="L141" rel="#L141">141</span>
<span id="L142" rel="#L142">142</span>
<span id="L143" rel="#L143">143</span>
<span id="L144" rel="#L144">144</span>
<span id="L145" rel="#L145">145</span>
<span id="L146" rel="#L146">146</span>
<span id="L147" rel="#L147">147</span>
<span id="L148" rel="#L148">148</span>
<span id="L149" rel="#L149">149</span>
<span id="L150" rel="#L150">150</span>
<span id="L151" rel="#L151">151</span>
<span id="L152" rel="#L152">152</span>
<span id="L153" rel="#L153">153</span>
<span id="L154" rel="#L154">154</span>
<span id="L155" rel="#L155">155</span>
<span id="L156" rel="#L156">156</span>
<span id="L157" rel="#L157">157</span>
<span id="L158" rel="#L158">158</span>
<span id="L159" rel="#L159">159</span>
<span id="L160" rel="#L160">160</span>
<span id="L161" rel="#L161">161</span>
<span id="L162" rel="#L162">162</span>
<span id="L163" rel="#L163">163</span>
<span id="L164" rel="#L164">164</span>
<span id="L165" rel="#L165">165</span>
<span id="L166" rel="#L166">166</span>
<span id="L167" rel="#L167">167</span>
<span id="L168" rel="#L168">168</span>
<span id="L169" rel="#L169">169</span>
<span id="L170" rel="#L170">170</span>
<span id="L171" rel="#L171">171</span>
<span id="L172" rel="#L172">172</span>
<span id="L173" rel="#L173">173</span>
<span id="L174" rel="#L174">174</span>
<span id="L175" rel="#L175">175</span>
<span id="L176" rel="#L176">176</span>
<span id="L177" rel="#L177">177</span>
<span id="L178" rel="#L178">178</span>
<span id="L179" rel="#L179">179</span>
<span id="L180" rel="#L180">180</span>
<span id="L181" rel="#L181">181</span>
<span id="L182" rel="#L182">182</span>
<span id="L183" rel="#L183">183</span>
<span id="L184" rel="#L184">184</span>
<span id="L185" rel="#L185">185</span>
<span id="L186" rel="#L186">186</span>
<span id="L187" rel="#L187">187</span>
<span id="L188" rel="#L188">188</span>
<span id="L189" rel="#L189">189</span>
<span id="L190" rel="#L190">190</span>
<span id="L191" rel="#L191">191</span>
<span id="L192" rel="#L192">192</span>
<span id="L193" rel="#L193">193</span>
<span id="L194" rel="#L194">194</span>
<span id="L195" rel="#L195">195</span>
<span id="L196" rel="#L196">196</span>
<span id="L197" rel="#L197">197</span>
<span id="L198" rel="#L198">198</span>
<span id="L199" rel="#L199">199</span>
<span id="L200" rel="#L200">200</span>
<span id="L201" rel="#L201">201</span>
<span id="L202" rel="#L202">202</span>
<span id="L203" rel="#L203">203</span>
<span id="L204" rel="#L204">204</span>
<span id="L205" rel="#L205">205</span>
<span id="L206" rel="#L206">206</span>
<span id="L207" rel="#L207">207</span>
<span id="L208" rel="#L208">208</span>
<span id="L209" rel="#L209">209</span>
<span id="L210" rel="#L210">210</span>
<span id="L211" rel="#L211">211</span>
<span id="L212" rel="#L212">212</span>
<span id="L213" rel="#L213">213</span>
<span id="L214" rel="#L214">214</span>
<span id="L215" rel="#L215">215</span>
<span id="L216" rel="#L216">216</span>
<span id="L217" rel="#L217">217</span>
<span id="L218" rel="#L218">218</span>
<span id="L219" rel="#L219">219</span>
<span id="L220" rel="#L220">220</span>
<span id="L221" rel="#L221">221</span>
<span id="L222" rel="#L222">222</span>
<span id="L223" rel="#L223">223</span>
<span id="L224" rel="#L224">224</span>
<span id="L225" rel="#L225">225</span>
<span id="L226" rel="#L226">226</span>
<span id="L227" rel="#L227">227</span>
<span id="L228" rel="#L228">228</span>
<span id="L229" rel="#L229">229</span>
<span id="L230" rel="#L230">230</span>
<span id="L231" rel="#L231">231</span>
<span id="L232" rel="#L232">232</span>
<span id="L233" rel="#L233">233</span>
<span id="L234" rel="#L234">234</span>
<span id="L235" rel="#L235">235</span>
<span id="L236" rel="#L236">236</span>
<span id="L237" rel="#L237">237</span>
<span id="L238" rel="#L238">238</span>
<span id="L239" rel="#L239">239</span>
<span id="L240" rel="#L240">240</span>
<span id="L241" rel="#L241">241</span>
<span id="L242" rel="#L242">242</span>
<span id="L243" rel="#L243">243</span>
<span id="L244" rel="#L244">244</span>
<span id="L245" rel="#L245">245</span>
<span id="L246" rel="#L246">246</span>
<span id="L247" rel="#L247">247</span>
<span id="L248" rel="#L248">248</span>
<span id="L249" rel="#L249">249</span>
<span id="L250" rel="#L250">250</span>
<span id="L251" rel="#L251">251</span>
<span id="L252" rel="#L252">252</span>
<span id="L253" rel="#L253">253</span>
<span id="L254" rel="#L254">254</span>
<span id="L255" rel="#L255">255</span>
<span id="L256" rel="#L256">256</span>
<span id="L257" rel="#L257">257</span>
<span id="L258" rel="#L258">258</span>
<span id="L259" rel="#L259">259</span>
<span id="L260" rel="#L260">260</span>
<span id="L261" rel="#L261">261</span>
<span id="L262" rel="#L262">262</span>
<span id="L263" rel="#L263">263</span>
<span id="L264" rel="#L264">264</span>
<span id="L265" rel="#L265">265</span>
<span id="L266" rel="#L266">266</span>
<span id="L267" rel="#L267">267</span>
<span id="L268" rel="#L268">268</span>
<span id="L269" rel="#L269">269</span>
<span id="L270" rel="#L270">270</span>
<span id="L271" rel="#L271">271</span>
<span id="L272" rel="#L272">272</span>
<span id="L273" rel="#L273">273</span>
<span id="L274" rel="#L274">274</span>
<span id="L275" rel="#L275">275</span>
<span id="L276" rel="#L276">276</span>
<span id="L277" rel="#L277">277</span>
<span id="L278" rel="#L278">278</span>
<span id="L279" rel="#L279">279</span>
<span id="L280" rel="#L280">280</span>
<span id="L281" rel="#L281">281</span>
<span id="L282" rel="#L282">282</span>
<span id="L283" rel="#L283">283</span>
<span id="L284" rel="#L284">284</span>
<span id="L285" rel="#L285">285</span>
<span id="L286" rel="#L286">286</span>
<span id="L287" rel="#L287">287</span>
<span id="L288" rel="#L288">288</span>
<span id="L289" rel="#L289">289</span>
<span id="L290" rel="#L290">290</span>
<span id="L291" rel="#L291">291</span>
<span id="L292" rel="#L292">292</span>
<span id="L293" rel="#L293">293</span>
<span id="L294" rel="#L294">294</span>
<span id="L295" rel="#L295">295</span>
<span id="L296" rel="#L296">296</span>
<span id="L297" rel="#L297">297</span>
<span id="L298" rel="#L298">298</span>
<span id="L299" rel="#L299">299</span>
<span id="L300" rel="#L300">300</span>
<span id="L301" rel="#L301">301</span>
<span id="L302" rel="#L302">302</span>
<span id="L303" rel="#L303">303</span>
<span id="L304" rel="#L304">304</span>
<span id="L305" rel="#L305">305</span>
<span id="L306" rel="#L306">306</span>
<span id="L307" rel="#L307">307</span>
<span id="L308" rel="#L308">308</span>
<span id="L309" rel="#L309">309</span>
<span id="L310" rel="#L310">310</span>
<span id="L311" rel="#L311">311</span>
<span id="L312" rel="#L312">312</span>
<span id="L313" rel="#L313">313</span>
<span id="L314" rel="#L314">314</span>
<span id="L315" rel="#L315">315</span>
<span id="L316" rel="#L316">316</span>
<span id="L317" rel="#L317">317</span>
<span id="L318" rel="#L318">318</span>
<span id="L319" rel="#L319">319</span>
<span id="L320" rel="#L320">320</span>
<span id="L321" rel="#L321">321</span>
<span id="L322" rel="#L322">322</span>
<span id="L323" rel="#L323">323</span>
<span id="L324" rel="#L324">324</span>
<span id="L325" rel="#L325">325</span>
<span id="L326" rel="#L326">326</span>
<span id="L327" rel="#L327">327</span>
<span id="L328" rel="#L328">328</span>
<span id="L329" rel="#L329">329</span>
<span id="L330" rel="#L330">330</span>
<span id="L331" rel="#L331">331</span>
<span id="L332" rel="#L332">332</span>
<span id="L333" rel="#L333">333</span>
<span id="L334" rel="#L334">334</span>
<span id="L335" rel="#L335">335</span>
<span id="L336" rel="#L336">336</span>
<span id="L337" rel="#L337">337</span>
<span id="L338" rel="#L338">338</span>
<span id="L339" rel="#L339">339</span>
<span id="L340" rel="#L340">340</span>
<span id="L341" rel="#L341">341</span>
<span id="L342" rel="#L342">342</span>
<span id="L343" rel="#L343">343</span>
<span id="L344" rel="#L344">344</span>
<span id="L345" rel="#L345">345</span>
<span id="L346" rel="#L346">346</span>
<span id="L347" rel="#L347">347</span>
<span id="L348" rel="#L348">348</span>
<span id="L349" rel="#L349">349</span>
<span id="L350" rel="#L350">350</span>
<span id="L351" rel="#L351">351</span>
<span id="L352" rel="#L352">352</span>
<span id="L353" rel="#L353">353</span>
<span id="L354" rel="#L354">354</span>
<span id="L355" rel="#L355">355</span>
<span id="L356" rel="#L356">356</span>
<span id="L357" rel="#L357">357</span>
<span id="L358" rel="#L358">358</span>
<span id="L359" rel="#L359">359</span>
<span id="L360" rel="#L360">360</span>
<span id="L361" rel="#L361">361</span>
<span id="L362" rel="#L362">362</span>
<span id="L363" rel="#L363">363</span>
<span id="L364" rel="#L364">364</span>
<span id="L365" rel="#L365">365</span>
<span id="L366" rel="#L366">366</span>
<span id="L367" rel="#L367">367</span>
<span id="L368" rel="#L368">368</span>
<span id="L369" rel="#L369">369</span>
<span id="L370" rel="#L370">370</span>
<span id="L371" rel="#L371">371</span>
<span id="L372" rel="#L372">372</span>
<span id="L373" rel="#L373">373</span>
<span id="L374" rel="#L374">374</span>
<span id="L375" rel="#L375">375</span>
<span id="L376" rel="#L376">376</span>
<span id="L377" rel="#L377">377</span>
<span id="L378" rel="#L378">378</span>
<span id="L379" rel="#L379">379</span>
<span id="L380" rel="#L380">380</span>
<span id="L381" rel="#L381">381</span>
<span id="L382" rel="#L382">382</span>
<span id="L383" rel="#L383">383</span>
<span id="L384" rel="#L384">384</span>
<span id="L385" rel="#L385">385</span>
<span id="L386" rel="#L386">386</span>
<span id="L387" rel="#L387">387</span>
<span id="L388" rel="#L388">388</span>
<span id="L389" rel="#L389">389</span>
<span id="L390" rel="#L390">390</span>
<span id="L391" rel="#L391">391</span>
<span id="L392" rel="#L392">392</span>
<span id="L393" rel="#L393">393</span>
<span id="L394" rel="#L394">394</span>
<span id="L395" rel="#L395">395</span>
<span id="L396" rel="#L396">396</span>
<span id="L397" rel="#L397">397</span>
<span id="L398" rel="#L398">398</span>
<span id="L399" rel="#L399">399</span>
<span id="L400" rel="#L400">400</span>
<span id="L401" rel="#L401">401</span>
<span id="L402" rel="#L402">402</span>
<span id="L403" rel="#L403">403</span>
<span id="L404" rel="#L404">404</span>
<span id="L405" rel="#L405">405</span>
<span id="L406" rel="#L406">406</span>
<span id="L407" rel="#L407">407</span>
<span id="L408" rel="#L408">408</span>
<span id="L409" rel="#L409">409</span>
<span id="L410" rel="#L410">410</span>
<span id="L411" rel="#L411">411</span>
<span id="L412" rel="#L412">412</span>
<span id="L413" rel="#L413">413</span>
<span id="L414" rel="#L414">414</span>
<span id="L415" rel="#L415">415</span>
<span id="L416" rel="#L416">416</span>
<span id="L417" rel="#L417">417</span>
<span id="L418" rel="#L418">418</span>
<span id="L419" rel="#L419">419</span>
<span id="L420" rel="#L420">420</span>
<span id="L421" rel="#L421">421</span>
<span id="L422" rel="#L422">422</span>
<span id="L423" rel="#L423">423</span>
<span id="L424" rel="#L424">424</span>
<span id="L425" rel="#L425">425</span>
<span id="L426" rel="#L426">426</span>
<span id="L427" rel="#L427">427</span>
<span id="L428" rel="#L428">428</span>
<span id="L429" rel="#L429">429</span>
<span id="L430" rel="#L430">430</span>
<span id="L431" rel="#L431">431</span>
<span id="L432" rel="#L432">432</span>
<span id="L433" rel="#L433">433</span>
<span id="L434" rel="#L434">434</span>
<span id="L435" rel="#L435">435</span>
<span id="L436" rel="#L436">436</span>
<span id="L437" rel="#L437">437</span>
<span id="L438" rel="#L438">438</span>
<span id="L439" rel="#L439">439</span>
<span id="L440" rel="#L440">440</span>
<span id="L441" rel="#L441">441</span>
<span id="L442" rel="#L442">442</span>
<span id="L443" rel="#L443">443</span>
<span id="L444" rel="#L444">444</span>
<span id="L445" rel="#L445">445</span>
<span id="L446" rel="#L446">446</span>
<span id="L447" rel="#L447">447</span>
<span id="L448" rel="#L448">448</span>
<span id="L449" rel="#L449">449</span>
<span id="L450" rel="#L450">450</span>
<span id="L451" rel="#L451">451</span>
<span id="L452" rel="#L452">452</span>
<span id="L453" rel="#L453">453</span>
<span id="L454" rel="#L454">454</span>
<span id="L455" rel="#L455">455</span>
<span id="L456" rel="#L456">456</span>
<span id="L457" rel="#L457">457</span>
<span id="L458" rel="#L458">458</span>
<span id="L459" rel="#L459">459</span>
<span id="L460" rel="#L460">460</span>
<span id="L461" rel="#L461">461</span>
<span id="L462" rel="#L462">462</span>
<span id="L463" rel="#L463">463</span>
<span id="L464" rel="#L464">464</span>
<span id="L465" rel="#L465">465</span>
<span id="L466" rel="#L466">466</span>
<span id="L467" rel="#L467">467</span>
<span id="L468" rel="#L468">468</span>
<span id="L469" rel="#L469">469</span>
<span id="L470" rel="#L470">470</span>
<span id="L471" rel="#L471">471</span>
<span id="L472" rel="#L472">472</span>
<span id="L473" rel="#L473">473</span>
<span id="L474" rel="#L474">474</span>
<span id="L475" rel="#L475">475</span>
<span id="L476" rel="#L476">476</span>
<span id="L477" rel="#L477">477</span>
<span id="L478" rel="#L478">478</span>
<span id="L479" rel="#L479">479</span>
<span id="L480" rel="#L480">480</span>
<span id="L481" rel="#L481">481</span>
<span id="L482" rel="#L482">482</span>
<span id="L483" rel="#L483">483</span>
<span id="L484" rel="#L484">484</span>
<span id="L485" rel="#L485">485</span>
<span id="L486" rel="#L486">486</span>
<span id="L487" rel="#L487">487</span>
<span id="L488" rel="#L488">488</span>
<span id="L489" rel="#L489">489</span>
<span id="L490" rel="#L490">490</span>
<span id="L491" rel="#L491">491</span>
<span id="L492" rel="#L492">492</span>
<span id="L493" rel="#L493">493</span>
<span id="L494" rel="#L494">494</span>
<span id="L495" rel="#L495">495</span>
<span id="L496" rel="#L496">496</span>
<span id="L497" rel="#L497">497</span>
<span id="L498" rel="#L498">498</span>
<span id="L499" rel="#L499">499</span>
<span id="L500" rel="#L500">500</span>
<span id="L501" rel="#L501">501</span>
<span id="L502" rel="#L502">502</span>
<span id="L503" rel="#L503">503</span>
<span id="L504" rel="#L504">504</span>
<span id="L505" rel="#L505">505</span>
<span id="L506" rel="#L506">506</span>
<span id="L507" rel="#L507">507</span>
<span id="L508" rel="#L508">508</span>
<span id="L509" rel="#L509">509</span>
<span id="L510" rel="#L510">510</span>
<span id="L511" rel="#L511">511</span>
<span id="L512" rel="#L512">512</span>
<span id="L513" rel="#L513">513</span>
<span id="L514" rel="#L514">514</span>
<span id="L515" rel="#L515">515</span>
<span id="L516" rel="#L516">516</span>
<span id="L517" rel="#L517">517</span>
<span id="L518" rel="#L518">518</span>
<span id="L519" rel="#L519">519</span>
<span id="L520" rel="#L520">520</span>
<span id="L521" rel="#L521">521</span>
<span id="L522" rel="#L522">522</span>
<span id="L523" rel="#L523">523</span>
<span id="L524" rel="#L524">524</span>
<span id="L525" rel="#L525">525</span>
<span id="L526" rel="#L526">526</span>
<span id="L527" rel="#L527">527</span>
<span id="L528" rel="#L528">528</span>
<span id="L529" rel="#L529">529</span>
<span id="L530" rel="#L530">530</span>
<span id="L531" rel="#L531">531</span>
<span id="L532" rel="#L532">532</span>
<span id="L533" rel="#L533">533</span>
<span id="L534" rel="#L534">534</span>
<span id="L535" rel="#L535">535</span>
<span id="L536" rel="#L536">536</span>
<span id="L537" rel="#L537">537</span>
<span id="L538" rel="#L538">538</span>
<span id="L539" rel="#L539">539</span>
<span id="L540" rel="#L540">540</span>
<span id="L541" rel="#L541">541</span>
<span id="L542" rel="#L542">542</span>
<span id="L543" rel="#L543">543</span>
<span id="L544" rel="#L544">544</span>
<span id="L545" rel="#L545">545</span>
<span id="L546" rel="#L546">546</span>
<span id="L547" rel="#L547">547</span>
<span id="L548" rel="#L548">548</span>
<span id="L549" rel="#L549">549</span>
<span id="L550" rel="#L550">550</span>
<span id="L551" rel="#L551">551</span>
<span id="L552" rel="#L552">552</span>
<span id="L553" rel="#L553">553</span>
<span id="L554" rel="#L554">554</span>
<span id="L555" rel="#L555">555</span>
<span id="L556" rel="#L556">556</span>
<span id="L557" rel="#L557">557</span>
<span id="L558" rel="#L558">558</span>
<span id="L559" rel="#L559">559</span>
<span id="L560" rel="#L560">560</span>
<span id="L561" rel="#L561">561</span>
<span id="L562" rel="#L562">562</span>
<span id="L563" rel="#L563">563</span>
<span id="L564" rel="#L564">564</span>
<span id="L565" rel="#L565">565</span>
</pre>
          </td>
          <td width="100%">
                <div class="highlight"><pre><div class='line' id='LC1'><span class="cp">// Adafruit Motor shield library</span></div><div class='line' id='LC2'><span class="cp">// copyright Adafruit Industries LLC, 2009</span></div><div class='line' id='LC3'><span class="cp">// this code is public domain, enjoy!</span></div><div class='line' id='LC4'><br/></div><div class='line' id='LC5'><br/></div><div class='line' id='LC6'><span class="cp">#if (ARDUINO &gt;= 100)</span></div><div class='line' id='LC7'><span class="cp"> #include &quot;Arduino.h&quot;</span></div><div class='line' id='LC8'><span class="cp">#else</span></div><div class='line' id='LC9'><span class="cp"> #include &lt;avr/io.h&gt;</span></div><div class='line' id='LC10'><span class="cp"> #include &quot;WProgram.h&quot;</span></div><div class='line' id='LC11'><span class="cp">#endif</span></div><div class='line' id='LC12'><span class="cp">#include &quot;AFMotor.h&quot;</span></div><div class='line' id='LC13'><br/></div><div class='line' id='LC14'><br/></div><div class='line' id='LC15'><br/></div><div class='line' id='LC16'><span class="k">static</span> <span class="n">uint8_t</span> <span class="n">latch_state</span><span class="p">;</span></div><div class='line' id='LC17'><br/></div><div class='line' id='LC18'><span class="cp">#if (MICROSTEPS == 8)</span></div><div class='line' id='LC19'><span class="n">uint8_t</span> <span class="n">microstepcurve</span><span class="p">[]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">0</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">98</span><span class="p">,</span> <span class="mi">142</span><span class="p">,</span> <span class="mi">180</span><span class="p">,</span> <span class="mi">212</span><span class="p">,</span> <span class="mi">236</span><span class="p">,</span> <span class="mi">250</span><span class="p">,</span> <span class="mi">255</span><span class="p">};</span></div><div class='line' id='LC20'><span class="cp">#elif (MICROSTEPS == 16)</span></div><div class='line' id='LC21'><span class="n">uint8_t</span> <span class="n">microstepcurve</span><span class="p">[]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">0</span><span class="p">,</span> <span class="mi">25</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">74</span><span class="p">,</span> <span class="mi">98</span><span class="p">,</span> <span class="mi">120</span><span class="p">,</span> <span class="mi">141</span><span class="p">,</span> <span class="mi">162</span><span class="p">,</span> <span class="mi">180</span><span class="p">,</span> <span class="mi">197</span><span class="p">,</span> <span class="mi">212</span><span class="p">,</span> <span class="mi">225</span><span class="p">,</span> <span class="mi">236</span><span class="p">,</span> <span class="mi">244</span><span class="p">,</span> <span class="mi">250</span><span class="p">,</span> <span class="mi">253</span><span class="p">,</span> <span class="mi">255</span><span class="p">};</span></div><div class='line' id='LC22'><span class="cp">#endif</span></div><div class='line' id='LC23'><br/></div><div class='line' id='LC24'><span class="n">AFMotorController</span><span class="o">::</span><span class="n">AFMotorController</span><span class="p">(</span><span class="kt">void</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC25'><span class="p">}</span></div><div class='line' id='LC26'><br/></div><div class='line' id='LC27'><span class="kt">void</span> <span class="n">AFMotorController</span><span class="o">::</span><span class="n">enable</span><span class="p">(</span><span class="kt">void</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC28'>&nbsp;&nbsp;<span class="c1">// setup the latch</span></div><div class='line' id='LC29'>&nbsp;&nbsp;<span class="cm">/*</span></div><div class='line' id='LC30'><span class="cm">  LATCH_DDR |= _BV(LATCH);</span></div><div class='line' id='LC31'><span class="cm">  ENABLE_DDR |= _BV(ENABLE);</span></div><div class='line' id='LC32'><span class="cm">  CLK_DDR |= _BV(CLK);</span></div><div class='line' id='LC33'><span class="cm">  SER_DDR |= _BV(SER);</span></div><div class='line' id='LC34'><span class="cm">  */</span></div><div class='line' id='LC35'>&nbsp;&nbsp;<span class="n">pinMode</span><span class="p">(</span><span class="n">MOTORLATCH</span><span class="p">,</span> <span class="n">OUTPUT</span><span class="p">);</span></div><div class='line' id='LC36'>&nbsp;&nbsp;<span class="n">pinMode</span><span class="p">(</span><span class="n">MOTORENABLE</span><span class="p">,</span> <span class="n">OUTPUT</span><span class="p">);</span></div><div class='line' id='LC37'>&nbsp;&nbsp;<span class="n">pinMode</span><span class="p">(</span><span class="n">MOTORDATA</span><span class="p">,</span> <span class="n">OUTPUT</span><span class="p">);</span></div><div class='line' id='LC38'>&nbsp;&nbsp;<span class="n">pinMode</span><span class="p">(</span><span class="n">MOTORCLK</span><span class="p">,</span> <span class="n">OUTPUT</span><span class="p">);</span></div><div class='line' id='LC39'><br/></div><div class='line' id='LC40'>&nbsp;&nbsp;<span class="n">latch_state</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC41'><br/></div><div class='line' id='LC42'>&nbsp;&nbsp;<span class="n">latch_tx</span><span class="p">();</span>  <span class="c1">// &quot;reset&quot;</span></div><div class='line' id='LC43'><br/></div><div class='line' id='LC44'>&nbsp;&nbsp;<span class="c1">//ENABLE_PORT &amp;= ~_BV(ENABLE); // enable the chip outputs!</span></div><div class='line' id='LC45'>&nbsp;&nbsp;<span class="n">digitalWrite</span><span class="p">(</span><span class="n">MOTORENABLE</span><span class="p">,</span> <span class="n">LOW</span><span class="p">);</span></div><div class='line' id='LC46'><span class="p">}</span></div><div class='line' id='LC47'><br/></div><div class='line' id='LC48'><br/></div><div class='line' id='LC49'><span class="kt">void</span> <span class="n">AFMotorController</span><span class="o">::</span><span class="n">latch_tx</span><span class="p">(</span><span class="kt">void</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC50'>&nbsp;&nbsp;<span class="n">uint8_t</span> <span class="n">i</span><span class="p">;</span></div><div class='line' id='LC51'><br/></div><div class='line' id='LC52'>&nbsp;&nbsp;<span class="c1">//LATCH_PORT &amp;= ~_BV(LATCH);</span></div><div class='line' id='LC53'>&nbsp;&nbsp;<span class="n">digitalWrite</span><span class="p">(</span><span class="n">MOTORLATCH</span><span class="p">,</span> <span class="n">LOW</span><span class="p">);</span></div><div class='line' id='LC54'><br/></div><div class='line' id='LC55'>&nbsp;&nbsp;<span class="c1">//SER_PORT &amp;= ~_BV(SER);</span></div><div class='line' id='LC56'>&nbsp;&nbsp;<span class="n">digitalWrite</span><span class="p">(</span><span class="n">MOTORDATA</span><span class="p">,</span> <span class="n">LOW</span><span class="p">);</span></div><div class='line' id='LC57'><br/></div><div class='line' id='LC58'>&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">i</span><span class="o">&lt;</span><span class="mi">8</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC59'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">//CLK_PORT &amp;= ~_BV(CLK);</span></div><div class='line' id='LC60'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">digitalWrite</span><span class="p">(</span><span class="n">MOTORCLK</span><span class="p">,</span> <span class="n">LOW</span><span class="p">);</span></div><div class='line' id='LC61'><br/></div><div class='line' id='LC62'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">latch_state</span> <span class="o">&amp;</span> <span class="n">_BV</span><span class="p">(</span><span class="mi">7</span><span class="o">-</span><span class="n">i</span><span class="p">))</span> <span class="p">{</span></div><div class='line' id='LC63'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">//SER_PORT |= _BV(SER);</span></div><div class='line' id='LC64'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">digitalWrite</span><span class="p">(</span><span class="n">MOTORDATA</span><span class="p">,</span> <span class="n">HIGH</span><span class="p">);</span></div><div class='line' id='LC65'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span> <span class="k">else</span> <span class="p">{</span></div><div class='line' id='LC66'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">//SER_PORT &amp;= ~_BV(SER);</span></div><div class='line' id='LC67'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">digitalWrite</span><span class="p">(</span><span class="n">MOTORDATA</span><span class="p">,</span> <span class="n">LOW</span><span class="p">);</span></div><div class='line' id='LC68'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC69'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">//CLK_PORT |= _BV(CLK);</span></div><div class='line' id='LC70'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">digitalWrite</span><span class="p">(</span><span class="n">MOTORCLK</span><span class="p">,</span> <span class="n">HIGH</span><span class="p">);</span></div><div class='line' id='LC71'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC72'>&nbsp;&nbsp;<span class="c1">//LATCH_PORT |= _BV(LATCH);</span></div><div class='line' id='LC73'>&nbsp;&nbsp;<span class="n">digitalWrite</span><span class="p">(</span><span class="n">MOTORLATCH</span><span class="p">,</span> <span class="n">HIGH</span><span class="p">);</span></div><div class='line' id='LC74'><span class="p">}</span></div><div class='line' id='LC75'><br/></div><div class='line' id='LC76'><span class="k">static</span> <span class="n">AFMotorController</span> <span class="n">MC</span><span class="p">;</span></div><div class='line' id='LC77'><br/></div><div class='line' id='LC78'><br/></div><div class='line' id='LC79'><span class="cm">/******************************************</span></div><div class='line' id='LC80'><span class="cm">               MOTORS</span></div><div class='line' id='LC81'><span class="cm">******************************************/</span></div><div class='line' id='LC82'><span class="kr">inline</span> <span class="kt">void</span> <span class="n">initPWM1</span><span class="p">(</span><span class="n">uint8_t</span> <span class="n">freq</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC83'><span class="cp">#if defined(__AVR_ATmega8__) || \</span></div><div class='line' id='LC84'><span class="cp">    defined(__AVR_ATmega48__) || \</span></div><div class='line' id='LC85'><span class="cp">    defined(__AVR_ATmega88__) || \</span></div><div class='line' id='LC86'><span class="cp">    defined(__AVR_ATmega168__) || \</span></div><div class='line' id='LC87'><span class="cp">    defined(__AVR_ATmega328P__)</span></div><div class='line' id='LC88'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// use PWM from timer2A on PB3 (Arduino pin #11)</span></div><div class='line' id='LC89'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">TCCR2A</span> <span class="o">|=</span> <span class="n">_BV</span><span class="p">(</span><span class="n">COM2A1</span><span class="p">)</span> <span class="o">|</span> <span class="n">_BV</span><span class="p">(</span><span class="n">WGM20</span><span class="p">)</span> <span class="o">|</span> <span class="n">_BV</span><span class="p">(</span><span class="n">WGM21</span><span class="p">);</span> <span class="c1">// fast PWM, turn on oc2a</span></div><div class='line' id='LC90'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">TCCR2B</span> <span class="o">=</span> <span class="n">freq</span> <span class="o">&amp;</span> <span class="mh">0x7</span><span class="p">;</span></div><div class='line' id='LC91'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">OCR2A</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC92'><span class="cp">#elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)</span></div><div class='line' id='LC93'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// on arduino mega, pin 11 is now PB5 (OC1A)</span></div><div class='line' id='LC94'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">TCCR1A</span> <span class="o">|=</span> <span class="n">_BV</span><span class="p">(</span><span class="n">COM1A1</span><span class="p">)</span> <span class="o">|</span> <span class="n">_BV</span><span class="p">(</span><span class="n">WGM10</span><span class="p">);</span> <span class="c1">// fast PWM, turn on oc1a</span></div><div class='line' id='LC95'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">TCCR1B</span> <span class="o">=</span> <span class="p">(</span><span class="n">freq</span> <span class="o">&amp;</span> <span class="mh">0x7</span><span class="p">)</span> <span class="o">|</span> <span class="n">_BV</span><span class="p">(</span><span class="n">WGM12</span><span class="p">);</span></div><div class='line' id='LC96'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">OCR1A</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC97'><span class="cp">#else</span></div><div class='line' id='LC98'><span class="cp">   #error &quot;This chip is not supported!&quot;</span></div><div class='line' id='LC99'><span class="cp">#endif</span></div><div class='line' id='LC100'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">pinMode</span><span class="p">(</span><span class="mi">11</span><span class="p">,</span> <span class="n">OUTPUT</span><span class="p">);</span></div><div class='line' id='LC101'><span class="p">}</span></div><div class='line' id='LC102'><br/></div><div class='line' id='LC103'><span class="kr">inline</span> <span class="kt">void</span> <span class="n">setPWM1</span><span class="p">(</span><span class="n">uint8_t</span> <span class="n">s</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC104'><span class="cp">#if defined(__AVR_ATmega8__) || \</span></div><div class='line' id='LC105'><span class="cp">    defined(__AVR_ATmega48__) || \</span></div><div class='line' id='LC106'><span class="cp">    defined(__AVR_ATmega88__) || \</span></div><div class='line' id='LC107'><span class="cp">    defined(__AVR_ATmega168__) || \</span></div><div class='line' id='LC108'><span class="cp">    defined(__AVR_ATmega328P__)</span></div><div class='line' id='LC109'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// use PWM from timer2A on PB3 (Arduino pin #11)</span></div><div class='line' id='LC110'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">OCR2A</span> <span class="o">=</span> <span class="n">s</span><span class="p">;</span></div><div class='line' id='LC111'><span class="cp">#elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)</span></div><div class='line' id='LC112'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// on arduino mega, pin 11 is now PB5 (OC1A)</span></div><div class='line' id='LC113'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">OCR1A</span> <span class="o">=</span> <span class="n">s</span><span class="p">;</span></div><div class='line' id='LC114'><span class="cp">#else</span></div><div class='line' id='LC115'><span class="cp">   #error &quot;This chip is not supported!&quot;</span></div><div class='line' id='LC116'><span class="cp">#endif</span></div><div class='line' id='LC117'><span class="p">}</span></div><div class='line' id='LC118'><br/></div><div class='line' id='LC119'><span class="kr">inline</span> <span class="kt">void</span> <span class="n">initPWM2</span><span class="p">(</span><span class="n">uint8_t</span> <span class="n">freq</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC120'><span class="cp">#if defined(__AVR_ATmega8__) || \</span></div><div class='line' id='LC121'><span class="cp">    defined(__AVR_ATmega48__) || \</span></div><div class='line' id='LC122'><span class="cp">    defined(__AVR_ATmega88__) || \</span></div><div class='line' id='LC123'><span class="cp">    defined(__AVR_ATmega168__) || \</span></div><div class='line' id='LC124'><span class="cp">    defined(__AVR_ATmega328P__)</span></div><div class='line' id='LC125'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// use PWM from timer2B (pin 3)</span></div><div class='line' id='LC126'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">TCCR2A</span> <span class="o">|=</span> <span class="n">_BV</span><span class="p">(</span><span class="n">COM2B1</span><span class="p">)</span> <span class="o">|</span> <span class="n">_BV</span><span class="p">(</span><span class="n">WGM20</span><span class="p">)</span> <span class="o">|</span> <span class="n">_BV</span><span class="p">(</span><span class="n">WGM21</span><span class="p">);</span> <span class="c1">// fast PWM, turn on oc2b</span></div><div class='line' id='LC127'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">TCCR2B</span> <span class="o">=</span> <span class="n">freq</span> <span class="o">&amp;</span> <span class="mh">0x7</span><span class="p">;</span></div><div class='line' id='LC128'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">OCR2B</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC129'><span class="cp">#elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)</span></div><div class='line' id='LC130'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// on arduino mega, pin 3 is now PE5 (OC3C)</span></div><div class='line' id='LC131'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">TCCR3A</span> <span class="o">|=</span> <span class="n">_BV</span><span class="p">(</span><span class="n">COM1C1</span><span class="p">)</span> <span class="o">|</span> <span class="n">_BV</span><span class="p">(</span><span class="n">WGM10</span><span class="p">);</span> <span class="c1">// fast PWM, turn on oc3c</span></div><div class='line' id='LC132'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">TCCR3B</span> <span class="o">=</span> <span class="p">(</span><span class="n">freq</span> <span class="o">&amp;</span> <span class="mh">0x7</span><span class="p">)</span> <span class="o">|</span> <span class="n">_BV</span><span class="p">(</span><span class="n">WGM12</span><span class="p">);</span></div><div class='line' id='LC133'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">OCR3C</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC134'><span class="cp">#else</span></div><div class='line' id='LC135'><span class="cp">   #error &quot;This chip is not supported!&quot;</span></div><div class='line' id='LC136'><span class="cp">#endif</span></div><div class='line' id='LC137'><br/></div><div class='line' id='LC138'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">pinMode</span><span class="p">(</span><span class="mi">3</span><span class="p">,</span> <span class="n">OUTPUT</span><span class="p">);</span></div><div class='line' id='LC139'><span class="p">}</span></div><div class='line' id='LC140'><br/></div><div class='line' id='LC141'><span class="kr">inline</span> <span class="kt">void</span> <span class="n">setPWM2</span><span class="p">(</span><span class="n">uint8_t</span> <span class="n">s</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC142'><span class="cp">#if defined(__AVR_ATmega8__) || \</span></div><div class='line' id='LC143'><span class="cp">    defined(__AVR_ATmega48__) || \</span></div><div class='line' id='LC144'><span class="cp">    defined(__AVR_ATmega88__) || \</span></div><div class='line' id='LC145'><span class="cp">    defined(__AVR_ATmega168__) || \</span></div><div class='line' id='LC146'><span class="cp">    defined(__AVR_ATmega328P__)</span></div><div class='line' id='LC147'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// use PWM from timer2A on PB3 (Arduino pin #11)</span></div><div class='line' id='LC148'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">OCR2B</span> <span class="o">=</span> <span class="n">s</span><span class="p">;</span></div><div class='line' id='LC149'><span class="cp">#elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)</span></div><div class='line' id='LC150'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// on arduino mega, pin 11 is now PB5 (OC1A)</span></div><div class='line' id='LC151'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">OCR3C</span> <span class="o">=</span> <span class="n">s</span><span class="p">;</span></div><div class='line' id='LC152'><span class="cp">#else</span></div><div class='line' id='LC153'><span class="cp">   #error &quot;This chip is not supported!&quot;</span></div><div class='line' id='LC154'><span class="cp">#endif</span></div><div class='line' id='LC155'><span class="p">}</span></div><div class='line' id='LC156'><br/></div><div class='line' id='LC157'><span class="kr">inline</span> <span class="kt">void</span> <span class="n">initPWM3</span><span class="p">(</span><span class="n">uint8_t</span> <span class="n">freq</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC158'><span class="cp">#if defined(__AVR_ATmega8__) || \</span></div><div class='line' id='LC159'><span class="cp">    defined(__AVR_ATmega48__) || \</span></div><div class='line' id='LC160'><span class="cp">    defined(__AVR_ATmega88__) || \</span></div><div class='line' id='LC161'><span class="cp">    defined(__AVR_ATmega168__) || \</span></div><div class='line' id='LC162'><span class="cp">    defined(__AVR_ATmega328P__)</span></div><div class='line' id='LC163'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// use PWM from timer0A / PD6 (pin 6)</span></div><div class='line' id='LC164'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">TCCR0A</span> <span class="o">|=</span> <span class="n">_BV</span><span class="p">(</span><span class="n">COM0A1</span><span class="p">)</span> <span class="o">|</span> <span class="n">_BV</span><span class="p">(</span><span class="n">WGM00</span><span class="p">)</span> <span class="o">|</span> <span class="n">_BV</span><span class="p">(</span><span class="n">WGM01</span><span class="p">);</span> <span class="c1">// fast PWM, turn on OC0A</span></div><div class='line' id='LC165'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">//TCCR0B = freq &amp; 0x7;</span></div><div class='line' id='LC166'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">OCR0A</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC167'><span class="cp">#elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)</span></div><div class='line' id='LC168'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// on arduino mega, pin 6 is now PH3 (OC4A)</span></div><div class='line' id='LC169'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">TCCR4A</span> <span class="o">|=</span> <span class="n">_BV</span><span class="p">(</span><span class="n">COM1A1</span><span class="p">)</span> <span class="o">|</span> <span class="n">_BV</span><span class="p">(</span><span class="n">WGM10</span><span class="p">);</span> <span class="c1">// fast PWM, turn on oc4a</span></div><div class='line' id='LC170'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">TCCR4B</span> <span class="o">=</span> <span class="p">(</span><span class="n">freq</span> <span class="o">&amp;</span> <span class="mh">0x7</span><span class="p">)</span> <span class="o">|</span> <span class="n">_BV</span><span class="p">(</span><span class="n">WGM12</span><span class="p">);</span></div><div class='line' id='LC171'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">//TCCR4B = 1 | _BV(WGM12);</span></div><div class='line' id='LC172'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">OCR4A</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC173'><span class="cp">#else</span></div><div class='line' id='LC174'><span class="cp">   #error &quot;This chip is not supported!&quot;</span></div><div class='line' id='LC175'><span class="cp">#endif</span></div><div class='line' id='LC176'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">pinMode</span><span class="p">(</span><span class="mi">6</span><span class="p">,</span> <span class="n">OUTPUT</span><span class="p">);</span></div><div class='line' id='LC177'><span class="p">}</span></div><div class='line' id='LC178'><br/></div><div class='line' id='LC179'><span class="kr">inline</span> <span class="kt">void</span> <span class="n">setPWM3</span><span class="p">(</span><span class="n">uint8_t</span> <span class="n">s</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC180'><span class="cp">#if defined(__AVR_ATmega8__) || \</span></div><div class='line' id='LC181'><span class="cp">    defined(__AVR_ATmega48__) || \</span></div><div class='line' id='LC182'><span class="cp">    defined(__AVR_ATmega88__) || \</span></div><div class='line' id='LC183'><span class="cp">    defined(__AVR_ATmega168__) || \</span></div><div class='line' id='LC184'><span class="cp">    defined(__AVR_ATmega328P__)</span></div><div class='line' id='LC185'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// use PWM from timer0A on PB3 (Arduino pin #6)</span></div><div class='line' id='LC186'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">OCR0A</span> <span class="o">=</span> <span class="n">s</span><span class="p">;</span></div><div class='line' id='LC187'><span class="cp">#elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)</span></div><div class='line' id='LC188'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// on arduino mega, pin 6 is now PH3 (OC4A)</span></div><div class='line' id='LC189'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">OCR4A</span> <span class="o">=</span> <span class="n">s</span><span class="p">;</span></div><div class='line' id='LC190'><span class="cp">#else</span></div><div class='line' id='LC191'><span class="cp">   #error &quot;This chip is not supported!&quot;</span></div><div class='line' id='LC192'><span class="cp">#endif</span></div><div class='line' id='LC193'><span class="p">}</span></div><div class='line' id='LC194'><br/></div><div class='line' id='LC195'><br/></div><div class='line' id='LC196'><br/></div><div class='line' id='LC197'><span class="kr">inline</span> <span class="kt">void</span> <span class="n">initPWM4</span><span class="p">(</span><span class="n">uint8_t</span> <span class="n">freq</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC198'><span class="cp">#if defined(__AVR_ATmega8__) || \</span></div><div class='line' id='LC199'><span class="cp">    defined(__AVR_ATmega48__) || \</span></div><div class='line' id='LC200'><span class="cp">    defined(__AVR_ATmega88__) || \</span></div><div class='line' id='LC201'><span class="cp">    defined(__AVR_ATmega168__) || \</span></div><div class='line' id='LC202'><span class="cp">    defined(__AVR_ATmega328P__)</span></div><div class='line' id='LC203'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// use PWM from timer0B / PD5 (pin 5)</span></div><div class='line' id='LC204'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">TCCR0A</span> <span class="o">|=</span> <span class="n">_BV</span><span class="p">(</span><span class="n">COM0B1</span><span class="p">)</span> <span class="o">|</span> <span class="n">_BV</span><span class="p">(</span><span class="n">WGM00</span><span class="p">)</span> <span class="o">|</span> <span class="n">_BV</span><span class="p">(</span><span class="n">WGM01</span><span class="p">);</span> <span class="c1">// fast PWM, turn on oc0a</span></div><div class='line' id='LC205'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">//TCCR0B = freq &amp; 0x7;</span></div><div class='line' id='LC206'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">OCR0B</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC207'><span class="cp">#elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)</span></div><div class='line' id='LC208'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// on arduino mega, pin 5 is now PE3 (OC3A)</span></div><div class='line' id='LC209'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">TCCR3A</span> <span class="o">|=</span> <span class="n">_BV</span><span class="p">(</span><span class="n">COM1A1</span><span class="p">)</span> <span class="o">|</span> <span class="n">_BV</span><span class="p">(</span><span class="n">WGM10</span><span class="p">);</span> <span class="c1">// fast PWM, turn on oc3a</span></div><div class='line' id='LC210'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">TCCR3B</span> <span class="o">=</span> <span class="p">(</span><span class="n">freq</span> <span class="o">&amp;</span> <span class="mh">0x7</span><span class="p">)</span> <span class="o">|</span> <span class="n">_BV</span><span class="p">(</span><span class="n">WGM12</span><span class="p">);</span></div><div class='line' id='LC211'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">//TCCR4B = 1 | _BV(WGM12);</span></div><div class='line' id='LC212'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">OCR3A</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC213'><span class="cp">#else</span></div><div class='line' id='LC214'><span class="cp">   #error &quot;This chip is not supported!&quot;</span></div><div class='line' id='LC215'><span class="cp">#endif</span></div><div class='line' id='LC216'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">pinMode</span><span class="p">(</span><span class="mi">5</span><span class="p">,</span> <span class="n">OUTPUT</span><span class="p">);</span></div><div class='line' id='LC217'><span class="p">}</span></div><div class='line' id='LC218'><br/></div><div class='line' id='LC219'><span class="kr">inline</span> <span class="kt">void</span> <span class="n">setPWM4</span><span class="p">(</span><span class="n">uint8_t</span> <span class="n">s</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC220'><span class="cp">#if defined(__AVR_ATmega8__) || \</span></div><div class='line' id='LC221'><span class="cp">    defined(__AVR_ATmega48__) || \</span></div><div class='line' id='LC222'><span class="cp">    defined(__AVR_ATmega88__) || \</span></div><div class='line' id='LC223'><span class="cp">    defined(__AVR_ATmega168__) || \</span></div><div class='line' id='LC224'><span class="cp">    defined(__AVR_ATmega328P__)</span></div><div class='line' id='LC225'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// use PWM from timer0A on PB3 (Arduino pin #6)</span></div><div class='line' id='LC226'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">OCR0B</span> <span class="o">=</span> <span class="n">s</span><span class="p">;</span></div><div class='line' id='LC227'><span class="cp">#elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)</span></div><div class='line' id='LC228'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// on arduino mega, pin 6 is now PH3 (OC4A)</span></div><div class='line' id='LC229'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">OCR3A</span> <span class="o">=</span> <span class="n">s</span><span class="p">;</span></div><div class='line' id='LC230'><span class="cp">#else</span></div><div class='line' id='LC231'><span class="cp">   #error &quot;This chip is not supported!&quot;</span></div><div class='line' id='LC232'><span class="cp">#endif</span></div><div class='line' id='LC233'><span class="p">}</span></div><div class='line' id='LC234'><br/></div><div class='line' id='LC235'><span class="n">AF_DCMotor</span><span class="o">::</span><span class="n">AF_DCMotor</span><span class="p">(</span><span class="n">uint8_t</span> <span class="n">num</span><span class="p">,</span> <span class="n">uint8_t</span> <span class="n">freq</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC236'>&nbsp;&nbsp;<span class="n">motornum</span> <span class="o">=</span> <span class="n">num</span><span class="p">;</span></div><div class='line' id='LC237'>&nbsp;&nbsp;<span class="n">pwmfreq</span> <span class="o">=</span> <span class="n">freq</span><span class="p">;</span></div><div class='line' id='LC238'><br/></div><div class='line' id='LC239'>&nbsp;&nbsp;<span class="n">MC</span><span class="p">.</span><span class="n">enable</span><span class="p">();</span></div><div class='line' id='LC240'><br/></div><div class='line' id='LC241'>&nbsp;&nbsp;<span class="k">switch</span> <span class="p">(</span><span class="n">num</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC242'>&nbsp;&nbsp;<span class="k">case</span> <span class="mi">1</span><span class="o">:</span></div><div class='line' id='LC243'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">latch_state</span> <span class="o">&amp;=</span> <span class="o">~</span><span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR1_A</span><span class="p">)</span> <span class="o">&amp;</span> <span class="o">~</span><span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR1_B</span><span class="p">);</span> <span class="c1">// set both motor pins to 0</span></div><div class='line' id='LC244'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">MC</span><span class="p">.</span><span class="n">latch_tx</span><span class="p">();</span></div><div class='line' id='LC245'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">initPWM1</span><span class="p">(</span><span class="n">freq</span><span class="p">);</span></div><div class='line' id='LC246'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">break</span><span class="p">;</span></div><div class='line' id='LC247'>&nbsp;&nbsp;<span class="k">case</span> <span class="mi">2</span><span class="o">:</span></div><div class='line' id='LC248'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">latch_state</span> <span class="o">&amp;=</span> <span class="o">~</span><span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR2_A</span><span class="p">)</span> <span class="o">&amp;</span> <span class="o">~</span><span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR2_B</span><span class="p">);</span> <span class="c1">// set both motor pins to 0</span></div><div class='line' id='LC249'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">MC</span><span class="p">.</span><span class="n">latch_tx</span><span class="p">();</span></div><div class='line' id='LC250'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">initPWM2</span><span class="p">(</span><span class="n">freq</span><span class="p">);</span></div><div class='line' id='LC251'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">break</span><span class="p">;</span></div><div class='line' id='LC252'>&nbsp;&nbsp;<span class="k">case</span> <span class="mi">3</span><span class="o">:</span></div><div class='line' id='LC253'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">latch_state</span> <span class="o">&amp;=</span> <span class="o">~</span><span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR3_A</span><span class="p">)</span> <span class="o">&amp;</span> <span class="o">~</span><span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR3_B</span><span class="p">);</span> <span class="c1">// set both motor pins to 0</span></div><div class='line' id='LC254'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">MC</span><span class="p">.</span><span class="n">latch_tx</span><span class="p">();</span></div><div class='line' id='LC255'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">initPWM3</span><span class="p">(</span><span class="n">freq</span><span class="p">);</span></div><div class='line' id='LC256'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">break</span><span class="p">;</span></div><div class='line' id='LC257'>&nbsp;&nbsp;<span class="k">case</span> <span class="mi">4</span><span class="o">:</span></div><div class='line' id='LC258'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">latch_state</span> <span class="o">&amp;=</span> <span class="o">~</span><span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR4_A</span><span class="p">)</span> <span class="o">&amp;</span> <span class="o">~</span><span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR4_B</span><span class="p">);</span> <span class="c1">// set both motor pins to 0</span></div><div class='line' id='LC259'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">MC</span><span class="p">.</span><span class="n">latch_tx</span><span class="p">();</span></div><div class='line' id='LC260'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">initPWM4</span><span class="p">(</span><span class="n">freq</span><span class="p">);</span></div><div class='line' id='LC261'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">break</span><span class="p">;</span></div><div class='line' id='LC262'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC263'><span class="p">}</span></div><div class='line' id='LC264'><br/></div><div class='line' id='LC265'><span class="kt">void</span> <span class="n">AF_DCMotor</span><span class="o">::</span><span class="n">run</span><span class="p">(</span><span class="n">uint8_t</span> <span class="n">cmd</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC266'>&nbsp;&nbsp;<span class="n">uint8_t</span> <span class="n">a</span><span class="p">,</span> <span class="n">b</span><span class="p">;</span></div><div class='line' id='LC267'>&nbsp;&nbsp;<span class="k">switch</span> <span class="p">(</span><span class="n">motornum</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC268'>&nbsp;&nbsp;<span class="k">case</span> <span class="mi">1</span><span class="o">:</span></div><div class='line' id='LC269'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">a</span> <span class="o">=</span> <span class="n">MOTOR1_A</span><span class="p">;</span> <span class="n">b</span> <span class="o">=</span> <span class="n">MOTOR1_B</span><span class="p">;</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC270'>&nbsp;&nbsp;<span class="k">case</span> <span class="mi">2</span><span class="o">:</span></div><div class='line' id='LC271'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">a</span> <span class="o">=</span> <span class="n">MOTOR2_A</span><span class="p">;</span> <span class="n">b</span> <span class="o">=</span> <span class="n">MOTOR2_B</span><span class="p">;</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC272'>&nbsp;&nbsp;<span class="k">case</span> <span class="mi">3</span><span class="o">:</span></div><div class='line' id='LC273'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">a</span> <span class="o">=</span> <span class="n">MOTOR3_A</span><span class="p">;</span> <span class="n">b</span> <span class="o">=</span> <span class="n">MOTOR3_B</span><span class="p">;</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC274'>&nbsp;&nbsp;<span class="k">case</span> <span class="mi">4</span><span class="o">:</span></div><div class='line' id='LC275'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">a</span> <span class="o">=</span> <span class="n">MOTOR4_A</span><span class="p">;</span> <span class="n">b</span> <span class="o">=</span> <span class="n">MOTOR4_B</span><span class="p">;</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC276'>&nbsp;&nbsp;<span class="k">default</span><span class="o">:</span></div><div class='line' id='LC277'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">return</span><span class="p">;</span></div><div class='line' id='LC278'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC279'>&nbsp;&nbsp;</div><div class='line' id='LC280'>&nbsp;&nbsp;<span class="k">switch</span> <span class="p">(</span><span class="n">cmd</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC281'>&nbsp;&nbsp;<span class="k">case</span> <span class="nl">FORWARD:</span></div><div class='line' id='LC282'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">latch_state</span> <span class="o">|=</span> <span class="n">_BV</span><span class="p">(</span><span class="n">a</span><span class="p">);</span></div><div class='line' id='LC283'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">latch_state</span> <span class="o">&amp;=</span> <span class="o">~</span><span class="n">_BV</span><span class="p">(</span><span class="n">b</span><span class="p">);</span> </div><div class='line' id='LC284'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">MC</span><span class="p">.</span><span class="n">latch_tx</span><span class="p">();</span></div><div class='line' id='LC285'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">break</span><span class="p">;</span></div><div class='line' id='LC286'>&nbsp;&nbsp;<span class="k">case</span> <span class="nl">BACKWARD:</span></div><div class='line' id='LC287'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">latch_state</span> <span class="o">&amp;=</span> <span class="o">~</span><span class="n">_BV</span><span class="p">(</span><span class="n">a</span><span class="p">);</span></div><div class='line' id='LC288'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">latch_state</span> <span class="o">|=</span> <span class="n">_BV</span><span class="p">(</span><span class="n">b</span><span class="p">);</span> </div><div class='line' id='LC289'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">MC</span><span class="p">.</span><span class="n">latch_tx</span><span class="p">();</span></div><div class='line' id='LC290'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">break</span><span class="p">;</span></div><div class='line' id='LC291'>&nbsp;&nbsp;<span class="k">case</span> <span class="nl">RELEASE:</span></div><div class='line' id='LC292'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">latch_state</span> <span class="o">&amp;=</span> <span class="o">~</span><span class="n">_BV</span><span class="p">(</span><span class="n">a</span><span class="p">);</span></div><div class='line' id='LC293'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">latch_state</span> <span class="o">&amp;=</span> <span class="o">~</span><span class="n">_BV</span><span class="p">(</span><span class="n">b</span><span class="p">);</span> </div><div class='line' id='LC294'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">MC</span><span class="p">.</span><span class="n">latch_tx</span><span class="p">();</span></div><div class='line' id='LC295'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">break</span><span class="p">;</span></div><div class='line' id='LC296'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC297'><span class="p">}</span></div><div class='line' id='LC298'><br/></div><div class='line' id='LC299'><span class="kt">void</span> <span class="n">AF_DCMotor</span><span class="o">::</span><span class="n">setSpeed</span><span class="p">(</span><span class="n">uint8_t</span> <span class="n">speed</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC300'>&nbsp;&nbsp;<span class="k">switch</span> <span class="p">(</span><span class="n">motornum</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC301'>&nbsp;&nbsp;<span class="k">case</span> <span class="mi">1</span><span class="o">:</span></div><div class='line' id='LC302'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">setPWM1</span><span class="p">(</span><span class="n">speed</span><span class="p">);</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC303'>&nbsp;&nbsp;<span class="k">case</span> <span class="mi">2</span><span class="o">:</span></div><div class='line' id='LC304'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">setPWM2</span><span class="p">(</span><span class="n">speed</span><span class="p">);</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC305'>&nbsp;&nbsp;<span class="k">case</span> <span class="mi">3</span><span class="o">:</span></div><div class='line' id='LC306'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">setPWM3</span><span class="p">(</span><span class="n">speed</span><span class="p">);</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC307'>&nbsp;&nbsp;<span class="k">case</span> <span class="mi">4</span><span class="o">:</span></div><div class='line' id='LC308'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">setPWM4</span><span class="p">(</span><span class="n">speed</span><span class="p">);</span> <span class="k">break</span><span class="p">;</span></div><div class='line' id='LC309'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC310'><span class="p">}</span></div><div class='line' id='LC311'><br/></div><div class='line' id='LC312'><span class="cm">/******************************************</span></div><div class='line' id='LC313'><span class="cm">               STEPPERS</span></div><div class='line' id='LC314'><span class="cm">******************************************/</span></div><div class='line' id='LC315'><br/></div><div class='line' id='LC316'><span class="n">AF_Stepper</span><span class="o">::</span><span class="n">AF_Stepper</span><span class="p">(</span><span class="n">uint16_t</span> <span class="n">steps</span><span class="p">,</span> <span class="n">uint8_t</span> <span class="n">num</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC317'>&nbsp;&nbsp;<span class="n">MC</span><span class="p">.</span><span class="n">enable</span><span class="p">();</span></div><div class='line' id='LC318'><br/></div><div class='line' id='LC319'>&nbsp;&nbsp;<span class="n">revsteps</span> <span class="o">=</span> <span class="n">steps</span><span class="p">;</span></div><div class='line' id='LC320'>&nbsp;&nbsp;<span class="n">steppernum</span> <span class="o">=</span> <span class="n">num</span><span class="p">;</span></div><div class='line' id='LC321'>&nbsp;&nbsp;<span class="n">currentstep</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC322'><br/></div><div class='line' id='LC323'>&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">steppernum</span> <span class="o">==</span> <span class="mi">1</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC324'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">latch_state</span> <span class="o">&amp;=</span> <span class="o">~</span><span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR1_A</span><span class="p">)</span> <span class="o">&amp;</span> <span class="o">~</span><span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR1_B</span><span class="p">)</span> <span class="o">&amp;</span></div><div class='line' id='LC325'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="o">~</span><span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR2_A</span><span class="p">)</span> <span class="o">&amp;</span> <span class="o">~</span><span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR2_B</span><span class="p">);</span> <span class="c1">// all motor pins to 0</span></div><div class='line' id='LC326'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">MC</span><span class="p">.</span><span class="n">latch_tx</span><span class="p">();</span></div><div class='line' id='LC327'>&nbsp;&nbsp;&nbsp;&nbsp;</div><div class='line' id='LC328'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// enable both H bridges</span></div><div class='line' id='LC329'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">pinMode</span><span class="p">(</span><span class="mi">11</span><span class="p">,</span> <span class="n">OUTPUT</span><span class="p">);</span></div><div class='line' id='LC330'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">pinMode</span><span class="p">(</span><span class="mi">3</span><span class="p">,</span> <span class="n">OUTPUT</span><span class="p">);</span></div><div class='line' id='LC331'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">digitalWrite</span><span class="p">(</span><span class="mi">11</span><span class="p">,</span> <span class="n">HIGH</span><span class="p">);</span></div><div class='line' id='LC332'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">digitalWrite</span><span class="p">(</span><span class="mi">3</span><span class="p">,</span> <span class="n">HIGH</span><span class="p">);</span></div><div class='line' id='LC333'><br/></div><div class='line' id='LC334'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// use PWM for microstepping support</span></div><div class='line' id='LC335'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">initPWM1</span><span class="p">(</span><span class="n">MOTOR12_64KHZ</span><span class="p">);</span></div><div class='line' id='LC336'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">initPWM2</span><span class="p">(</span><span class="n">MOTOR12_64KHZ</span><span class="p">);</span></div><div class='line' id='LC337'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">setPWM1</span><span class="p">(</span><span class="mi">255</span><span class="p">);</span></div><div class='line' id='LC338'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">setPWM2</span><span class="p">(</span><span class="mi">255</span><span class="p">);</span></div><div class='line' id='LC339'><br/></div><div class='line' id='LC340'>&nbsp;&nbsp;<span class="p">}</span> <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">steppernum</span> <span class="o">==</span> <span class="mi">2</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC341'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">latch_state</span> <span class="o">&amp;=</span> <span class="o">~</span><span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR3_A</span><span class="p">)</span> <span class="o">&amp;</span> <span class="o">~</span><span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR3_B</span><span class="p">)</span> <span class="o">&amp;</span></div><div class='line' id='LC342'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="o">~</span><span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR4_A</span><span class="p">)</span> <span class="o">&amp;</span> <span class="o">~</span><span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR4_B</span><span class="p">);</span> <span class="c1">// all motor pins to 0</span></div><div class='line' id='LC343'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">MC</span><span class="p">.</span><span class="n">latch_tx</span><span class="p">();</span></div><div class='line' id='LC344'><br/></div><div class='line' id='LC345'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// enable both H bridges</span></div><div class='line' id='LC346'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">pinMode</span><span class="p">(</span><span class="mi">5</span><span class="p">,</span> <span class="n">OUTPUT</span><span class="p">);</span></div><div class='line' id='LC347'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">pinMode</span><span class="p">(</span><span class="mi">6</span><span class="p">,</span> <span class="n">OUTPUT</span><span class="p">);</span></div><div class='line' id='LC348'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">digitalWrite</span><span class="p">(</span><span class="mi">5</span><span class="p">,</span> <span class="n">HIGH</span><span class="p">);</span></div><div class='line' id='LC349'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">digitalWrite</span><span class="p">(</span><span class="mi">6</span><span class="p">,</span> <span class="n">HIGH</span><span class="p">);</span></div><div class='line' id='LC350'><br/></div><div class='line' id='LC351'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// use PWM for microstepping support</span></div><div class='line' id='LC352'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// use PWM for microstepping support</span></div><div class='line' id='LC353'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">initPWM3</span><span class="p">(</span><span class="mi">1</span><span class="p">);</span></div><div class='line' id='LC354'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">initPWM4</span><span class="p">(</span><span class="mi">1</span><span class="p">);</span></div><div class='line' id='LC355'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">setPWM3</span><span class="p">(</span><span class="mi">255</span><span class="p">);</span></div><div class='line' id='LC356'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">setPWM4</span><span class="p">(</span><span class="mi">255</span><span class="p">);</span></div><div class='line' id='LC357'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC358'><span class="p">}</span></div><div class='line' id='LC359'><br/></div><div class='line' id='LC360'><span class="kt">void</span> <span class="n">AF_Stepper</span><span class="o">::</span><span class="n">setSpeed</span><span class="p">(</span><span class="n">uint16_t</span> <span class="n">rpm</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC361'>&nbsp;&nbsp;<span class="n">usperstep</span> <span class="o">=</span> <span class="mi">60000000</span> <span class="o">/</span> <span class="p">((</span><span class="n">uint32_t</span><span class="p">)</span><span class="n">revsteps</span> <span class="o">*</span> <span class="p">(</span><span class="n">uint32_t</span><span class="p">)</span><span class="n">rpm</span><span class="p">);</span></div><div class='line' id='LC362'>&nbsp;&nbsp;<span class="n">steppingcounter</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC363'><span class="p">}</span></div><div class='line' id='LC364'><br/></div><div class='line' id='LC365'><span class="kt">void</span> <span class="n">AF_Stepper</span><span class="o">::</span><span class="n">release</span><span class="p">(</span><span class="kt">void</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC366'>&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">steppernum</span> <span class="o">==</span> <span class="mi">1</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC367'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">latch_state</span> <span class="o">&amp;=</span> <span class="o">~</span><span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR1_A</span><span class="p">)</span> <span class="o">&amp;</span> <span class="o">~</span><span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR1_B</span><span class="p">)</span> <span class="o">&amp;</span></div><div class='line' id='LC368'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="o">~</span><span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR2_A</span><span class="p">)</span> <span class="o">&amp;</span> <span class="o">~</span><span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR2_B</span><span class="p">);</span> <span class="c1">// all motor pins to 0</span></div><div class='line' id='LC369'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">MC</span><span class="p">.</span><span class="n">latch_tx</span><span class="p">();</span></div><div class='line' id='LC370'>&nbsp;&nbsp;<span class="p">}</span> <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">steppernum</span> <span class="o">==</span> <span class="mi">2</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC371'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">latch_state</span> <span class="o">&amp;=</span> <span class="o">~</span><span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR3_A</span><span class="p">)</span> <span class="o">&amp;</span> <span class="o">~</span><span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR3_B</span><span class="p">)</span> <span class="o">&amp;</span></div><div class='line' id='LC372'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="o">~</span><span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR4_A</span><span class="p">)</span> <span class="o">&amp;</span> <span class="o">~</span><span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR4_B</span><span class="p">);</span> <span class="c1">// all motor pins to 0</span></div><div class='line' id='LC373'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">MC</span><span class="p">.</span><span class="n">latch_tx</span><span class="p">();</span></div><div class='line' id='LC374'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC375'><span class="p">}</span></div><div class='line' id='LC376'><br/></div><div class='line' id='LC377'><span class="kt">void</span> <span class="n">AF_Stepper</span><span class="o">::</span><span class="n">step</span><span class="p">(</span><span class="n">uint16_t</span> <span class="n">steps</span><span class="p">,</span> <span class="n">uint8_t</span> <span class="n">dir</span><span class="p">,</span>  <span class="n">uint8_t</span> <span class="n">style</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC378'>&nbsp;&nbsp;<span class="n">uint32_t</span> <span class="n">uspers</span> <span class="o">=</span> <span class="n">usperstep</span><span class="p">;</span></div><div class='line' id='LC379'>&nbsp;&nbsp;<span class="n">uint8_t</span> <span class="n">ret</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC380'><br/></div><div class='line' id='LC381'>&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">style</span> <span class="o">==</span> <span class="n">INTERLEAVE</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC382'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">uspers</span> <span class="o">/=</span> <span class="mi">2</span><span class="p">;</span></div><div class='line' id='LC383'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC384'>&nbsp;<span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">style</span> <span class="o">==</span> <span class="n">MICROSTEP</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC385'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">uspers</span> <span class="o">/=</span> <span class="n">MICROSTEPS</span><span class="p">;</span></div><div class='line' id='LC386'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">steps</span> <span class="o">*=</span> <span class="n">MICROSTEPS</span><span class="p">;</span></div><div class='line' id='LC387'><span class="cp">#ifdef MOTORDEBUG</span></div><div class='line' id='LC388'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">Serial</span><span class="p">.</span><span class="n">print</span><span class="p">(</span><span class="s">&quot;steps = &quot;</span><span class="p">);</span> <span class="n">Serial</span><span class="p">.</span><span class="n">println</span><span class="p">(</span><span class="n">steps</span><span class="p">,</span> <span class="n">DEC</span><span class="p">);</span></div><div class='line' id='LC389'><span class="cp">#endif</span></div><div class='line' id='LC390'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC391'><br/></div><div class='line' id='LC392'>&nbsp;&nbsp;<span class="k">while</span> <span class="p">(</span><span class="n">steps</span><span class="o">--</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC393'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">ret</span> <span class="o">=</span> <span class="n">onestep</span><span class="p">(</span><span class="n">dir</span><span class="p">,</span> <span class="n">style</span><span class="p">);</span></div><div class='line' id='LC394'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">delay</span><span class="p">(</span><span class="n">uspers</span><span class="o">/</span><span class="mi">1000</span><span class="p">);</span> <span class="c1">// in ms</span></div><div class='line' id='LC395'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">steppingcounter</span> <span class="o">+=</span> <span class="p">(</span><span class="n">uspers</span> <span class="o">%</span> <span class="mi">1000</span><span class="p">);</span></div><div class='line' id='LC396'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">steppingcounter</span> <span class="o">&gt;=</span> <span class="mi">1000</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC397'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">delay</span><span class="p">(</span><span class="mi">1</span><span class="p">);</span></div><div class='line' id='LC398'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">steppingcounter</span> <span class="o">-=</span> <span class="mi">1000</span><span class="p">;</span></div><div class='line' id='LC399'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC400'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC401'>&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">style</span> <span class="o">==</span> <span class="n">MICROSTEP</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC402'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">while</span> <span class="p">((</span><span class="n">ret</span> <span class="o">!=</span> <span class="mi">0</span><span class="p">)</span> <span class="o">&amp;&amp;</span> <span class="p">(</span><span class="n">ret</span> <span class="o">!=</span> <span class="n">MICROSTEPS</span><span class="p">))</span> <span class="p">{</span></div><div class='line' id='LC403'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">ret</span> <span class="o">=</span> <span class="n">onestep</span><span class="p">(</span><span class="n">dir</span><span class="p">,</span> <span class="n">style</span><span class="p">);</span></div><div class='line' id='LC404'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">delay</span><span class="p">(</span><span class="n">uspers</span><span class="o">/</span><span class="mi">1000</span><span class="p">);</span> <span class="c1">// in ms</span></div><div class='line' id='LC405'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">steppingcounter</span> <span class="o">+=</span> <span class="p">(</span><span class="n">uspers</span> <span class="o">%</span> <span class="mi">1000</span><span class="p">);</span></div><div class='line' id='LC406'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">steppingcounter</span> <span class="o">&gt;=</span> <span class="mi">1000</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC407'>	<span class="n">delay</span><span class="p">(</span><span class="mi">1</span><span class="p">);</span></div><div class='line' id='LC408'>	<span class="n">steppingcounter</span> <span class="o">-=</span> <span class="mi">1000</span><span class="p">;</span></div><div class='line' id='LC409'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span> </div><div class='line' id='LC410'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC411'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC412'><span class="p">}</span></div><div class='line' id='LC413'><br/></div><div class='line' id='LC414'><span class="n">uint8_t</span> <span class="n">AF_Stepper</span><span class="o">::</span><span class="n">onestep</span><span class="p">(</span><span class="n">uint8_t</span> <span class="n">dir</span><span class="p">,</span> <span class="n">uint8_t</span> <span class="n">style</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC415'>&nbsp;&nbsp;<span class="n">uint8_t</span> <span class="n">a</span><span class="p">,</span> <span class="n">b</span><span class="p">,</span> <span class="n">c</span><span class="p">,</span> <span class="n">d</span><span class="p">;</span></div><div class='line' id='LC416'>&nbsp;&nbsp;<span class="n">uint8_t</span> <span class="n">ocrb</span><span class="p">,</span> <span class="n">ocra</span><span class="p">;</span></div><div class='line' id='LC417'><br/></div><div class='line' id='LC418'>&nbsp;&nbsp;<span class="n">ocra</span> <span class="o">=</span> <span class="n">ocrb</span> <span class="o">=</span> <span class="mi">255</span><span class="p">;</span></div><div class='line' id='LC419'><br/></div><div class='line' id='LC420'>&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">steppernum</span> <span class="o">==</span> <span class="mi">1</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC421'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">a</span> <span class="o">=</span> <span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR1_A</span><span class="p">);</span></div><div class='line' id='LC422'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">b</span> <span class="o">=</span> <span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR2_A</span><span class="p">);</span></div><div class='line' id='LC423'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">c</span> <span class="o">=</span> <span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR1_B</span><span class="p">);</span></div><div class='line' id='LC424'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">d</span> <span class="o">=</span> <span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR2_B</span><span class="p">);</span></div><div class='line' id='LC425'>&nbsp;&nbsp;<span class="p">}</span> <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">steppernum</span> <span class="o">==</span> <span class="mi">2</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC426'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">a</span> <span class="o">=</span> <span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR3_A</span><span class="p">);</span></div><div class='line' id='LC427'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">b</span> <span class="o">=</span> <span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR4_A</span><span class="p">);</span></div><div class='line' id='LC428'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">c</span> <span class="o">=</span> <span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR3_B</span><span class="p">);</span></div><div class='line' id='LC429'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">d</span> <span class="o">=</span> <span class="n">_BV</span><span class="p">(</span><span class="n">MOTOR4_B</span><span class="p">);</span></div><div class='line' id='LC430'>&nbsp;&nbsp;<span class="p">}</span> <span class="k">else</span> <span class="p">{</span></div><div class='line' id='LC431'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">return</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC432'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC433'><br/></div><div class='line' id='LC434'>&nbsp;&nbsp;<span class="c1">// next determine what sort of stepping procedure we&#39;re up to</span></div><div class='line' id='LC435'>&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">style</span> <span class="o">==</span> <span class="n">SINGLE</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC436'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">((</span><span class="n">currentstep</span><span class="o">/</span><span class="p">(</span><span class="n">MICROSTEPS</span><span class="o">/</span><span class="mi">2</span><span class="p">))</span> <span class="o">%</span> <span class="mi">2</span><span class="p">)</span> <span class="p">{</span> <span class="c1">// we&#39;re at an odd step, weird</span></div><div class='line' id='LC437'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">dir</span> <span class="o">==</span> <span class="n">FORWARD</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC438'>	<span class="n">currentstep</span> <span class="o">+=</span> <span class="n">MICROSTEPS</span><span class="o">/</span><span class="mi">2</span><span class="p">;</span></div><div class='line' id='LC439'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC440'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">else</span> <span class="p">{</span></div><div class='line' id='LC441'>	<span class="n">currentstep</span> <span class="o">-=</span> <span class="n">MICROSTEPS</span><span class="o">/</span><span class="mi">2</span><span class="p">;</span></div><div class='line' id='LC442'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC443'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span> <span class="k">else</span> <span class="p">{</span>           <span class="c1">// go to the next even step</span></div><div class='line' id='LC444'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">dir</span> <span class="o">==</span> <span class="n">FORWARD</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC445'>	<span class="n">currentstep</span> <span class="o">+=</span> <span class="n">MICROSTEPS</span><span class="p">;</span></div><div class='line' id='LC446'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC447'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">else</span> <span class="p">{</span></div><div class='line' id='LC448'>	<span class="n">currentstep</span> <span class="o">-=</span> <span class="n">MICROSTEPS</span><span class="p">;</span></div><div class='line' id='LC449'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC450'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC451'>&nbsp;&nbsp;<span class="p">}</span> <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">style</span> <span class="o">==</span> <span class="n">DOUBLE</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC452'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="o">!</span> <span class="p">(</span><span class="n">currentstep</span><span class="o">/</span><span class="p">(</span><span class="n">MICROSTEPS</span><span class="o">/</span><span class="mi">2</span><span class="p">)</span> <span class="o">%</span> <span class="mi">2</span><span class="p">))</span> <span class="p">{</span> <span class="c1">// we&#39;re at an even step, weird</span></div><div class='line' id='LC453'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">dir</span> <span class="o">==</span> <span class="n">FORWARD</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC454'>	<span class="n">currentstep</span> <span class="o">+=</span> <span class="n">MICROSTEPS</span><span class="o">/</span><span class="mi">2</span><span class="p">;</span></div><div class='line' id='LC455'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span> <span class="k">else</span> <span class="p">{</span></div><div class='line' id='LC456'>	<span class="n">currentstep</span> <span class="o">-=</span> <span class="n">MICROSTEPS</span><span class="o">/</span><span class="mi">2</span><span class="p">;</span></div><div class='line' id='LC457'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC458'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span> <span class="k">else</span> <span class="p">{</span>           <span class="c1">// go to the next odd step</span></div><div class='line' id='LC459'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">dir</span> <span class="o">==</span> <span class="n">FORWARD</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC460'>	<span class="n">currentstep</span> <span class="o">+=</span> <span class="n">MICROSTEPS</span><span class="p">;</span></div><div class='line' id='LC461'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span> <span class="k">else</span> <span class="p">{</span></div><div class='line' id='LC462'>	<span class="n">currentstep</span> <span class="o">-=</span> <span class="n">MICROSTEPS</span><span class="p">;</span></div><div class='line' id='LC463'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC464'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC465'>&nbsp;&nbsp;<span class="p">}</span> <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">style</span> <span class="o">==</span> <span class="n">INTERLEAVE</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC466'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">dir</span> <span class="o">==</span> <span class="n">FORWARD</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC467'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">currentstep</span> <span class="o">+=</span> <span class="n">MICROSTEPS</span><span class="o">/</span><span class="mi">2</span><span class="p">;</span></div><div class='line' id='LC468'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span> <span class="k">else</span> <span class="p">{</span></div><div class='line' id='LC469'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">currentstep</span> <span class="o">-=</span> <span class="n">MICROSTEPS</span><span class="o">/</span><span class="mi">2</span><span class="p">;</span></div><div class='line' id='LC470'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC471'>&nbsp;&nbsp;<span class="p">}</span> </div><div class='line' id='LC472'><br/></div><div class='line' id='LC473'>&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">style</span> <span class="o">==</span> <span class="n">MICROSTEP</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC474'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">dir</span> <span class="o">==</span> <span class="n">FORWARD</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC475'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">currentstep</span><span class="o">++</span><span class="p">;</span></div><div class='line' id='LC476'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span> <span class="k">else</span> <span class="p">{</span></div><div class='line' id='LC477'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// BACKWARDS</span></div><div class='line' id='LC478'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">currentstep</span><span class="o">--</span><span class="p">;</span></div><div class='line' id='LC479'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC480'><br/></div><div class='line' id='LC481'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">currentstep</span> <span class="o">+=</span> <span class="n">MICROSTEPS</span><span class="o">*</span><span class="mi">4</span><span class="p">;</span></div><div class='line' id='LC482'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">currentstep</span> <span class="o">%=</span> <span class="n">MICROSTEPS</span><span class="o">*</span><span class="mi">4</span><span class="p">;</span></div><div class='line' id='LC483'><br/></div><div class='line' id='LC484'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">ocra</span> <span class="o">=</span> <span class="n">ocrb</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC485'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span> <span class="p">(</span><span class="n">currentstep</span> <span class="o">&gt;=</span> <span class="mi">0</span><span class="p">)</span> <span class="o">&amp;&amp;</span> <span class="p">(</span><span class="n">currentstep</span> <span class="o">&lt;</span> <span class="n">MICROSTEPS</span><span class="p">))</span> <span class="p">{</span></div><div class='line' id='LC486'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">ocra</span> <span class="o">=</span> <span class="n">microstepcurve</span><span class="p">[</span><span class="n">MICROSTEPS</span> <span class="o">-</span> <span class="n">currentstep</span><span class="p">];</span></div><div class='line' id='LC487'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">ocrb</span> <span class="o">=</span> <span class="n">microstepcurve</span><span class="p">[</span><span class="n">currentstep</span><span class="p">];</span></div><div class='line' id='LC488'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span> <span class="k">else</span> <span class="k">if</span>  <span class="p">(</span> <span class="p">(</span><span class="n">currentstep</span> <span class="o">&gt;=</span> <span class="n">MICROSTEPS</span><span class="p">)</span> <span class="o">&amp;&amp;</span> <span class="p">(</span><span class="n">currentstep</span> <span class="o">&lt;</span> <span class="n">MICROSTEPS</span><span class="o">*</span><span class="mi">2</span><span class="p">))</span> <span class="p">{</span></div><div class='line' id='LC489'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">ocra</span> <span class="o">=</span> <span class="n">microstepcurve</span><span class="p">[</span><span class="n">currentstep</span> <span class="o">-</span> <span class="n">MICROSTEPS</span><span class="p">];</span></div><div class='line' id='LC490'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">ocrb</span> <span class="o">=</span> <span class="n">microstepcurve</span><span class="p">[</span><span class="n">MICROSTEPS</span><span class="o">*</span><span class="mi">2</span> <span class="o">-</span> <span class="n">currentstep</span><span class="p">];</span></div><div class='line' id='LC491'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span> <span class="k">else</span> <span class="k">if</span>  <span class="p">(</span> <span class="p">(</span><span class="n">currentstep</span> <span class="o">&gt;=</span> <span class="n">MICROSTEPS</span><span class="o">*</span><span class="mi">2</span><span class="p">)</span> <span class="o">&amp;&amp;</span> <span class="p">(</span><span class="n">currentstep</span> <span class="o">&lt;</span> <span class="n">MICROSTEPS</span><span class="o">*</span><span class="mi">3</span><span class="p">))</span> <span class="p">{</span></div><div class='line' id='LC492'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">ocra</span> <span class="o">=</span> <span class="n">microstepcurve</span><span class="p">[</span><span class="n">MICROSTEPS</span><span class="o">*</span><span class="mi">3</span> <span class="o">-</span> <span class="n">currentstep</span><span class="p">];</span></div><div class='line' id='LC493'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">ocrb</span> <span class="o">=</span> <span class="n">microstepcurve</span><span class="p">[</span><span class="n">currentstep</span> <span class="o">-</span> <span class="n">MICROSTEPS</span><span class="o">*</span><span class="mi">2</span><span class="p">];</span></div><div class='line' id='LC494'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span> <span class="k">else</span> <span class="k">if</span>  <span class="p">(</span> <span class="p">(</span><span class="n">currentstep</span> <span class="o">&gt;=</span> <span class="n">MICROSTEPS</span><span class="o">*</span><span class="mi">3</span><span class="p">)</span> <span class="o">&amp;&amp;</span> <span class="p">(</span><span class="n">currentstep</span> <span class="o">&lt;</span> <span class="n">MICROSTEPS</span><span class="o">*</span><span class="mi">4</span><span class="p">))</span> <span class="p">{</span></div><div class='line' id='LC495'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">ocra</span> <span class="o">=</span> <span class="n">microstepcurve</span><span class="p">[</span><span class="n">currentstep</span> <span class="o">-</span> <span class="n">MICROSTEPS</span><span class="o">*</span><span class="mi">3</span><span class="p">];</span></div><div class='line' id='LC496'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">ocrb</span> <span class="o">=</span> <span class="n">microstepcurve</span><span class="p">[</span><span class="n">MICROSTEPS</span><span class="o">*</span><span class="mi">4</span> <span class="o">-</span> <span class="n">currentstep</span><span class="p">];</span></div><div class='line' id='LC497'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC498'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC499'><br/></div><div class='line' id='LC500'>&nbsp;&nbsp;<span class="n">currentstep</span> <span class="o">+=</span> <span class="n">MICROSTEPS</span><span class="o">*</span><span class="mi">4</span><span class="p">;</span></div><div class='line' id='LC501'>&nbsp;&nbsp;<span class="n">currentstep</span> <span class="o">%=</span> <span class="n">MICROSTEPS</span><span class="o">*</span><span class="mi">4</span><span class="p">;</span></div><div class='line' id='LC502'><br/></div><div class='line' id='LC503'><span class="cp">#ifdef MOTORDEBUG</span></div><div class='line' id='LC504'>&nbsp;&nbsp;<span class="n">Serial</span><span class="p">.</span><span class="n">print</span><span class="p">(</span><span class="s">&quot;current step: &quot;</span><span class="p">);</span> <span class="n">Serial</span><span class="p">.</span><span class="n">println</span><span class="p">(</span><span class="n">currentstep</span><span class="p">,</span> <span class="n">DEC</span><span class="p">);</span></div><div class='line' id='LC505'>&nbsp;&nbsp;<span class="n">Serial</span><span class="p">.</span><span class="n">print</span><span class="p">(</span><span class="s">&quot; pwmA = &quot;</span><span class="p">);</span> <span class="n">Serial</span><span class="p">.</span><span class="n">print</span><span class="p">(</span><span class="n">ocra</span><span class="p">,</span> <span class="n">DEC</span><span class="p">);</span> </div><div class='line' id='LC506'>&nbsp;&nbsp;<span class="n">Serial</span><span class="p">.</span><span class="n">print</span><span class="p">(</span><span class="s">&quot; pwmB = &quot;</span><span class="p">);</span> <span class="n">Serial</span><span class="p">.</span><span class="n">println</span><span class="p">(</span><span class="n">ocrb</span><span class="p">,</span> <span class="n">DEC</span><span class="p">);</span> </div><div class='line' id='LC507'><span class="cp">#endif</span></div><div class='line' id='LC508'><br/></div><div class='line' id='LC509'>&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">steppernum</span> <span class="o">==</span> <span class="mi">1</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC510'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">setPWM1</span><span class="p">(</span><span class="n">ocra</span><span class="p">);</span></div><div class='line' id='LC511'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">setPWM2</span><span class="p">(</span><span class="n">ocrb</span><span class="p">);</span></div><div class='line' id='LC512'>&nbsp;&nbsp;<span class="p">}</span> <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">steppernum</span> <span class="o">==</span> <span class="mi">2</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC513'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">setPWM3</span><span class="p">(</span><span class="n">ocra</span><span class="p">);</span></div><div class='line' id='LC514'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">setPWM4</span><span class="p">(</span><span class="n">ocrb</span><span class="p">);</span></div><div class='line' id='LC515'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC516'><br/></div><div class='line' id='LC517'><br/></div><div class='line' id='LC518'>&nbsp;&nbsp;<span class="c1">// release all</span></div><div class='line' id='LC519'>&nbsp;&nbsp;<span class="n">latch_state</span> <span class="o">&amp;=</span> <span class="o">~</span><span class="n">a</span> <span class="o">&amp;</span> <span class="o">~</span><span class="n">b</span> <span class="o">&amp;</span> <span class="o">~</span><span class="n">c</span> <span class="o">&amp;</span> <span class="o">~</span><span class="n">d</span><span class="p">;</span> <span class="c1">// all motor pins to 0</span></div><div class='line' id='LC520'><br/></div><div class='line' id='LC521'>&nbsp;&nbsp;<span class="c1">//Serial.println(step, DEC);</span></div><div class='line' id='LC522'>&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">style</span> <span class="o">==</span> <span class="n">MICROSTEP</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC523'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">((</span><span class="n">currentstep</span> <span class="o">&gt;=</span> <span class="mi">0</span><span class="p">)</span> <span class="o">&amp;&amp;</span> <span class="p">(</span><span class="n">currentstep</span> <span class="o">&lt;</span> <span class="n">MICROSTEPS</span><span class="p">))</span></div><div class='line' id='LC524'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">latch_state</span> <span class="o">|=</span> <span class="n">a</span> <span class="o">|</span> <span class="n">b</span><span class="p">;</span></div><div class='line' id='LC525'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">((</span><span class="n">currentstep</span> <span class="o">&gt;=</span> <span class="n">MICROSTEPS</span><span class="p">)</span> <span class="o">&amp;&amp;</span> <span class="p">(</span><span class="n">currentstep</span> <span class="o">&lt;</span> <span class="n">MICROSTEPS</span><span class="o">*</span><span class="mi">2</span><span class="p">))</span></div><div class='line' id='LC526'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">latch_state</span> <span class="o">|=</span> <span class="n">b</span> <span class="o">|</span> <span class="n">c</span><span class="p">;</span></div><div class='line' id='LC527'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">((</span><span class="n">currentstep</span> <span class="o">&gt;=</span> <span class="n">MICROSTEPS</span><span class="o">*</span><span class="mi">2</span><span class="p">)</span> <span class="o">&amp;&amp;</span> <span class="p">(</span><span class="n">currentstep</span> <span class="o">&lt;</span> <span class="n">MICROSTEPS</span><span class="o">*</span><span class="mi">3</span><span class="p">))</span></div><div class='line' id='LC528'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">latch_state</span> <span class="o">|=</span> <span class="n">c</span> <span class="o">|</span> <span class="n">d</span><span class="p">;</span></div><div class='line' id='LC529'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">((</span><span class="n">currentstep</span> <span class="o">&gt;=</span> <span class="n">MICROSTEPS</span><span class="o">*</span><span class="mi">3</span><span class="p">)</span> <span class="o">&amp;&amp;</span> <span class="p">(</span><span class="n">currentstep</span> <span class="o">&lt;</span> <span class="n">MICROSTEPS</span><span class="o">*</span><span class="mi">4</span><span class="p">))</span></div><div class='line' id='LC530'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">latch_state</span> <span class="o">|=</span> <span class="n">d</span> <span class="o">|</span> <span class="n">a</span><span class="p">;</span></div><div class='line' id='LC531'>&nbsp;&nbsp;<span class="p">}</span> <span class="k">else</span> <span class="p">{</span></div><div class='line' id='LC532'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">switch</span> <span class="p">(</span><span class="n">currentstep</span><span class="o">/</span><span class="p">(</span><span class="n">MICROSTEPS</span><span class="o">/</span><span class="mi">2</span><span class="p">))</span> <span class="p">{</span></div><div class='line' id='LC533'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">0</span><span class="o">:</span></div><div class='line' id='LC534'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">latch_state</span> <span class="o">|=</span> <span class="n">a</span><span class="p">;</span> <span class="c1">// energize coil 1 only</span></div><div class='line' id='LC535'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">break</span><span class="p">;</span></div><div class='line' id='LC536'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">1</span><span class="o">:</span></div><div class='line' id='LC537'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">latch_state</span> <span class="o">|=</span> <span class="n">a</span> <span class="o">|</span> <span class="n">b</span><span class="p">;</span> <span class="c1">// energize coil 1+2</span></div><div class='line' id='LC538'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">break</span><span class="p">;</span></div><div class='line' id='LC539'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">2</span><span class="o">:</span></div><div class='line' id='LC540'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">latch_state</span> <span class="o">|=</span> <span class="n">b</span><span class="p">;</span> <span class="c1">// energize coil 2 only</span></div><div class='line' id='LC541'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">break</span><span class="p">;</span></div><div class='line' id='LC542'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">3</span><span class="o">:</span></div><div class='line' id='LC543'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">latch_state</span> <span class="o">|=</span> <span class="n">b</span> <span class="o">|</span> <span class="n">c</span><span class="p">;</span> <span class="c1">// energize coil 2+3</span></div><div class='line' id='LC544'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">break</span><span class="p">;</span></div><div class='line' id='LC545'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">4</span><span class="o">:</span></div><div class='line' id='LC546'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">latch_state</span> <span class="o">|=</span> <span class="n">c</span><span class="p">;</span> <span class="c1">// energize coil 3 only</span></div><div class='line' id='LC547'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">break</span><span class="p">;</span> </div><div class='line' id='LC548'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">5</span><span class="o">:</span></div><div class='line' id='LC549'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">latch_state</span> <span class="o">|=</span> <span class="n">c</span> <span class="o">|</span> <span class="n">d</span><span class="p">;</span> <span class="c1">// energize coil 3+4</span></div><div class='line' id='LC550'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">break</span><span class="p">;</span></div><div class='line' id='LC551'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">6</span><span class="o">:</span></div><div class='line' id='LC552'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">latch_state</span> <span class="o">|=</span> <span class="n">d</span><span class="p">;</span> <span class="c1">// energize coil 4 only</span></div><div class='line' id='LC553'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">break</span><span class="p">;</span></div><div class='line' id='LC554'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">case</span> <span class="mi">7</span><span class="o">:</span></div><div class='line' id='LC555'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">latch_state</span> <span class="o">|=</span> <span class="n">d</span> <span class="o">|</span> <span class="n">a</span><span class="p">;</span> <span class="c1">// energize coil 1+4</span></div><div class='line' id='LC556'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">break</span><span class="p">;</span></div><div class='line' id='LC557'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC558'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC559'><br/></div><div class='line' id='LC560'>&nbsp;</div><div class='line' id='LC561'>&nbsp;&nbsp;<span class="n">MC</span><span class="p">.</span><span class="n">latch_tx</span><span class="p">();</span></div><div class='line' id='LC562'>&nbsp;&nbsp;<span class="k">return</span> <span class="n">currentstep</span><span class="p">;</span></div><div class='line' id='LC563'><span class="p">}</span></div><div class='line' id='LC564'><br/></div><div class='line' id='LC565'><br/></div></pre></div>
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

      <p>&copy; 2011 <span id="_rrt" title="0.06982s from fe9.rs.github.com">GitHub</span> Inc. All rights reserved.</p>
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

