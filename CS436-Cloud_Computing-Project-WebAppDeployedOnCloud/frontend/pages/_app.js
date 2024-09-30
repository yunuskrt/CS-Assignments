import React from 'react'

import 'bootstrap/dist/css/bootstrap.min.css'
import Layout from '@/components/layout'
function MyApp({ Component, pageProps }) {
	return <Layout app={<Component {...pageProps} />} />
}

export default MyApp
